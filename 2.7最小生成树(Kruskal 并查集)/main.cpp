#include <iostream>
#include <algorithm>
/*
并查集(数组 记录集合号)  配套方法：查找(递归) 合并

数据结构:
    数组 -> 存储集合号
    边数组
*/

using namespace std;

const int N = 100;
int father[N];
int n,m;

//边
struct Edge{
    int u;
    int v;
    int w;
}e[N*N];

//排序规则
bool comb(Edge e1,Edge e2){
    return e1.w<e2.w;//从小到大排序
}

//初始化father
void init(int n){
    for(int i=1;i<=n;i++){
        father[i] = i;
    }
}

//查找祖宗结点  !递归
int Find(int x){
    if(x!=father[x])
        father[x] = Find(father[x]);//在递推找祖宗的同时，回归的时候也将同一祖宗下的顶点都改成祖宗的集合号
    return father[x];
}

//合并  !当方法结果 有成功和失败 则需要返回值来判断是否成功
int Merge(int a,int b){// a b 为一条边的两个端点
    int p = Find(a);
    int q = Find(b);
    if(p==q) return 0;// 也就是说 当有回路时 就不能合并
    if(p>q)
        father[p] = q;// 并查集 约定 小的集合号赋值给大的集合号
    else
        father[q] = p;
    return 1;
}

int Kruskal(int n){
    int ans = 0;
    for(int i=0;i<m;i++){
        if(Merge(e[i].u,e[i].v)){
            ans += e[i].w;
            n--;
            if(n==1){
                return ans;
            }
        }
    }
    return 0;
}

int main()
{
    cout<<"输入结点数n和边数m:"<<endl;
    cin>>n>>m;
    init(n);
    cout<<"输入结点数u,v和边值w:"<<endl;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    sort(e,e+m,comb);
    int ans = Kruskal(n);
    cout<<ans<<endl;
    return 0;
}
