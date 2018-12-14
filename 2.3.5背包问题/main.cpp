#include <iostream>
#include <algorithm>
/*
2018年9月17日 12:18:22
算法策略：贪心算法
          贪心策略是以 物品的性价比进行贪心 从而得出最优解

编程技巧：结构体的使用
          sort排序 对复杂的数据结构排序 需要先定义排序规则

算法心得：1.贪心算法最重要的就是 要根据自己的目的挑选合适的贪心策略 不同的贪心策略 最终得出结果不一样
          2.所谓的贪心策略 目前看来说就是 优先挑选的标准
          3.背包问题：物品可以分割  0-1背包：物品不可分割（贪心算法可能只得出近似解）
*/
using namespace std;
const int M = 1000005;
//定义结构体 存储每种宝物的重量 价值 性价比
struct three{
    double w; //重量
    double v; //价值
    double p; //性价比
}s[M];
bool cmp(three a,three b){
 return a.p > b.p;//比较性价比
}
int main()
{
    int n;//表示有n个宝物
    double m;//毛驴的承受能力
    cout<<"请输入宝物的个数n和毛驴的承受能力m："<<endl;
    cin>>n>>m;
    cout<<"请输入每种宝物的重量和价值，用空格分开："<<endl;
    for(int i=0;i<n;i++){
        cin>>s[i].w>>s[i].v;
        s[i].p = s[i].v/s[i].w;
    }
    sort(s,s+n,cmp); // ！第三个参数是排序规则 对复杂的数据结构排序需要自己写
    double sum = 0.0; //宝物的价值之和
    for(int i=0;i<n;i++){
        if(s[i].w<=m){
            sum += s[i].v;
            m -= s[i].w;
        }else{
            sum += s[i].p*m;
            break;
        }
    }
    cout<<"最终装载最大价值为:"<<sum<<endl;
    return 0;
}
