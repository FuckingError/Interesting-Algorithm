#include <iostream>
#define N 100
using namespace std;
int G[N][N];
int n,m;//n 顶点数 m 边数
int i,j;
int x[N];//前面点的记录
int cn;//当前最大点

int bestn;//记录最优值
int bestx[N];//记录最优解
/*
2019年1月28日 01点13分
最大团问题 在一个无向图中找出最大的完全子图 完全子图就是子图中每个顶点都相连

回溯法
    约束条件:
        1.当前结点加入子图后，子图仍然维持完全子图
        2.没有剩余顶点
    限界条件:
        当前完全子图中的顶点+剩余顶点>当前最大值

比前一题 0-1背包简单...
*/

bool ifPlace(int t){//当前顶点是否可以放入子图
    for(i=1;i<t;i++){
        if(x[i]==1&&G[t][i]==0) return false;
    }
    return true;
}

void Backtrack(int t){
     //判断t是否<=n
    if(t>n){
        bestn = cn;
        for(i=1;i<=n;i++){
            bestx[i] = x[i];
        }
        return;
    }
    if(ifPlace(t)){//向左 放入子图
        cn++;
        x[t] = 1;
        Backtrack(t+1);
        cn--;
    }

    if(cn+n-t>bestn){//向右不放入子图中
        x[t] = 0;
        Backtrack(t+1);
    }
}

int main()
{
    int u,v;//边的两个顶点
    cout<<"顶点个数"<<endl;
    cin >> n;

    cout<<"边数"<<endl;
    cin >> m;

    cout<<"输入边"<<endl;
    for(i=1;i<=m;i++){
        cin>>u>>v;
        G[u][v] = 1;
        G[v][u] = 1;
    }
    Backtrack(1);
    cout<<"最大人数为:"<<bestn<<endl;
    for(i=1;i<=n;i++){
        if(bestx[i]) cout<<i<<" ";
    }
    return 0;
}
