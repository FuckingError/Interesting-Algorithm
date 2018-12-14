#include <iostream>
#define M 105
using namespace std;
/*
2018年12月14日 19:10:04
通过数组x[M]构造出了树的一个分支  厉害 厉害！！！

*/

int i,j,n,W;//n表示n个物品 W表示购物车的容量
double w[M],v[M];//w[i]表示第i个物品的重量 v[i]表示第i个物品的价值
bool x[M];//是否放入购物车
double cw;//当前重量
double cp;//当前价值
double bestp;//当前最优价值
bool bestx[M];//当前最优解

//当对t层 有右结点进行扩展前需计算上界  即需要计算t+1以及之后结点的价值之和
double Bound(int i){//从i层开始计算
    int rp = 0;
    while(i<=n){
        rp += v[i];
        i++;
    }
    return cp+rp;
}


// ! 这里的三个并列的if非常巧妙 要再好好研究一下
void Backtrack(int t){ //t表示当前扩展结点在第t层
    //如果此时已经达到叶子结点 则计算总价值 并进行更新
    //到达叶子结点的一定就是当前的最优解 可以覆盖上一个最优解
    /*因为： 首先如果从当前结点扩展右结点 会判断上界值是否大于当前最优值 如果大于才会进行遍历
             开始遍历后，如果一直是左结点直到结束，则此时结果必定是最优解
             而如果出现向右拓展，则又要判断上界值是否大于最优值，如果还大于，则继续往下左拓展，直到最后也必定是最优值
                                                                 如果小于的话，就不会往下拓展了.
             所以每次产生一个新的结果，则一定是最优解，这里也就不需要进行判断了

    */
    if(t>n){
        for(j=1;j<=n;j++){
            bestx[j] = x[j];//保存当前最优解  这里得到的结果一定是最优解
        }
        bestp = cp;//保存当前最优解
        return;
    }

    //搜索的显约束是cw<=W
    if(cw+w[t]<=W){
        x[t] = 1;//放入购物车
        cw += w[t];
        cp += v[t];
        Backtrack(t+1);
        //t-1层的左子树遍历完毕 回溯到当前t-1层 (减去t层的值)
        cw -= w[t];
        cp -= v[t];
    }
    //当前t-1层的左子树遍历完毕后 又回溯到t-1层 准备进行扩展右子树
    if(Bound(t+1)>bestp){//如果满足限制条件，则搜索右子树
        x[t] = 0;
        Backtrack(t+1);
    }
}

void Knapsack(double W,int n){
    //初始化
    cw = 0;
    cp = 0;
    bestp = 0;
    double sumw = 0.0;//统计所有物品总重量
    double sumv = 0.0;//统计所有物品价值

    //将所有物品加上看看是否小于当前容量，如果是，则都放入
    for(i=1;i<=n;i++){
        sumv+=v[i];
        sumw+=w[i];
    }
    if(sumw<=W){
        bestp=sumv;
        cout<<"最大价值为:"<<bestp<<endl;
        cout<<"所有的物品均放入购物车";
        return;
    }
    //正是开始搜索
    Backtrack(1);
    cout<<"放入购物车的物品最大价值为:"<<bestp<<endl;
    cout<<"放入购物车的物品编号为:";
    for(i=1;i<=n;i++){
        if(bestx[i]==1)
            cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    cout<<"请输入物品的个数n："<<endl;
    cin>>n;
    cout<<"请输入购物车的容量W:"<<endl;;
    cin>>W;
    cout<<"请依次输入每个物品的重量w和价值v，用空格隔开"<<endl;;
    for(i=1;i<=n;i++){// !为了方便 数组从1开始计数
        cin>>w[i]>>v[i];
    }
    Knapsack(W,n);
    return 0;
}
