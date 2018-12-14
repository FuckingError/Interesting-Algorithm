#include <iostream>
#include <algorithm>
/*
2018年10月9日 20:03:14
编程技巧：
    1.目前学到的第三种 表示图的方式  边集合
    2.sort 是algorithm中的方法  用法 sort(数组名，数组名+元素个数,排序方法)
        自定义排序方法 return < 就是从小到大
    3.将一个一个点 连成一副图
    4.避免构成回路的方法 这里是：判断一条边的两个顶点是否属于同一个集合
数据结构：
    边数组->存储边
    点数组->做标记 属于什么集合(将点连接起来)
*/
using namespace std;
const int N = 100;
int nodeset[N];
int n,m;

struct Edge{
    int u;
    int v;
    int w;
}e[N*N];

bool comp(Edge x,Edge y){
    return x.w < y.w;
}

//初始化顶点
void Init(int n){
    for(int i=1;i<=n;i++){
        nodeset[i] = i;
    }
}

int Merge(int a,int b){
    int p = nodeset[a];
    int q = nodeset[b];
    if(p==q) return 0;
    //检查所有结点 把结点是q的全部改成p
    for(int i=1;i<=n;i++){
        if(nodeset[i]==q){
            nodeset[i] = p;
        }
    }
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
    Init(n);
    cout<<"输入结点数u,v和边值w:"<<endl;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    sort(e,e+m,comp);
    int ans = Kruskal(n);
    cout<<ans<<endl;
}
