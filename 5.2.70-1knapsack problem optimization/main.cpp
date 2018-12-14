#include <iostream>
#include <cstring>
#include <algorithm>

#define M 105
using namespace std;
/*
2018年12月14日 21:40:15
主要的优化点在于：优化限界函数（因为原来限界函数是将剩余结点的价值统统加上，但是可能会出现虽然总价值大于最有价值，但是此时超过背包容量）
所以这里的限界函数要对背包容量进行限制，从而更加加快搜索

注意：
 1.memset 对应的头文件是 cstring
 2.sort   对应的头文件是 algorithm

*/
int i,j,n,W;//n是物品数量 W是购物车容量
double w[M],v[M];//物品重量 物品价值
bool x[M];//记录下每一层搜索后的选择
double cw = 0.0,cp = 0.0;//当前重量 当前价值

double bestp;//最优值
bool bestx[M];//存储最优选择


//结构体 用于对单位重量的物品价值进行排序 用于优化限界函数
struct Object{
    int id;//序号
    double w;
    double v;
    //double d;//单位重量的价值 用于排序的比较对象
};

bool cmp(Object o1,Object o2){// ! 按照物品单位重量价值由大到小排序
    return o1.v/o1.w>o2.v/o2.w;
}

double Bound(int i){//计算上界 !（这里就是优化的地方）  计算出剩余物品装满剩余背包容量所获得的最大价值
    double left = W-cw;//剩余容量
    double brp = 0.0;//剩余容量的最大价值
    // ! 不要他妈一循环 就想用for循环
    //计算最大价值
    //while(i<=n&&left>=0){  ！注意这里对剩余容量的判断条件 我写错了
    while(i<=n&&left>=w[i]){
        left -= w[i];
        brp += v[i];
        i++;
    }
    return brp;
}

void Backtrack(int t){//第t层
    if(t>n){//已经到达叶子结点
        for(i=1;i<=n;i++){
            bestx[i] = x[i];
        }
        bestp = cp;
        return;
    }

    //左结点 对应的是约束函数
    if(cw+w[t]<=W){
        //扩展左结点
        cw += w[t];
        cp += v[t];
        x[t] = 1;
        //继续往下遍历
        Backtrack(t+1);
        //这里一定要减去加上的w 和 v 进行下面的右结点遍历
        cw -= w[t];
        cp -= v[t];
    }

    //拓展右结点 限界函数
    if(Bound(t+1)+cp>bestp){ // ！ 判断条件可能会有多种写法 选择一种最直观的写法
        x[t] = 0;
        Backtrack(t+1);
    }

}

void Knapsack(){
    //对全局变量进行初始化
    //cw = 0;
    cw = 0;
    cp = 0;
    bestp = 0; // !要初始化全局变量啊
    double sumW=0.0,sumV=0.0;
    Object Q[n];
    memset(Q,0,sizeof(Object)*n);

    //物品全部都加起来 判断是否大于容量
    //同时 将v w输入到结构体数组中
    for(i=1;i<=n;i++){
        sumW += w[i];
        sumV += v[i];
        //输入到结构体中
        Q[i-1].id = i;
        Q[i-1].v = v[i];
        Q[i-1].w = w[i];
        //Q[i].d = v[i]/w[i];
    }

    if(sumV<=W){
        cout<<"全部都可以装入"<<endl;
        cout<<"放入购物车的最大价值为"<<sumV<<endl;
        return;
    }

    //排序
    sort(Q,Q+n,cmp);


    //重新输入到W 和 V数组中
    for(i=1;i<=n;i++){
        w[i] = Q[i-1].w;
        v[i] = Q[i-1].v;
    }
    //调用Backtrack
    Backtrack(1);
    cout<<"最大价值为:"<<bestp<<endl;
    cout<<"放入的物品序号为：";
    for(i=1;i<=n;i++){
        if(bestx[i]==1)
            cout<<Q[i-1].id<<" ";
    }
    cout<<endl;
}

int main()
{
    cout<<"物品数量和购物车容量："<<endl;
    cin>>n>>W;
    cout<<"输入物品重量和价值"<<endl;
    for(i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    Knapsack();
    return 0;
}
