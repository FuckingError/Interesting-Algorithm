#include <iostream>
#include <queue>
#include <cstring>
#include <windows.h>
/*
2018年10月6日 17:44:34
使用优先队列 降低复杂度（体现在选出当前v-s中距离s的最短路径）

编程技巧：
    1.struct 中可以使用构造函数
    2.重载 比较运算符
    3.优先队列
    4.数组 初始化函数 memset

*/
using namespace std;
const int N = 100;//城市数量
const int INF = 1e7;//无穷大
int map[N][N],dist[N],n,m;
bool flag[N];

struct Node{
    int u,step;//u是顶点 step是当前最短距离
    Node(){};
    Node(int a,int st){//构造函数
        u = a;
        step = st;
    }
    bool operator < (const Node& a)const{//参数 使用引用 参数是形参 主调函数中的变量复制一份  引用的话就是主调函数中变量本身
        return step>a.step;  // ！ 如果当前节点a.step大于b.step成立 则a<b成立(优先队列从大到小排列) 也就是b在上 a在下
    }
};

void Dijkstra(int st){
    priority_queue <Node> Q;//优先队列
    Q.push(Node(st,0));
    //初始化操作
    memset(flag,0,sizeof(flag)); //flag数组初始化为0
    for(int i=1;i<=n;i++){//初始化Dist
        dist[i] = INF;
    }
    dist[st] = 0;
    while(!Q.empty()){
        Node it = Q.top();//队头队列队头元素为最小值
        Q.pop();
        int t = it.u;
        if(flag[t])//说明已经找到了最短距离 该结点是队列里面的重复元素  比如：源点 终点是同一个  还有就是后面往队列中添加新元素 会有重复
            continue;
        //更新dist
        flag[t] = 1;
        for(int i=1;i<=n;i++){
            if(!flag[i]&&map[t][i]<INF){// 判断与当前点有关系的点 并且自己不能到自己
                if(dist[i]>dist[t]+map[t][i]){
                    dist[i] = dist[t]+map[t][i];
                    Q.push(Node(i,dist[i]));//会有重复的元素
                }
            }
        }
    }
}

int main()
{
    int u,v,w,st;
    system("color 0d");
    cout<<"请输入城市个数"<<endl;
    cin>>n;
    cout<<"请输入城市之间的路线的个数"<<endl;
    cin>>m;
    for(int i=1;i<=n;i++){//初始化邻接矩阵
        for(int j=1;j<=n;j++){
            map[i][j] = INF;
        }
    }
    cout<<"请输入城市之间u,v的路线以及距离w:"<<endl;
    while(m--){
        cin>>u>>v>>w;
        map[u][v]=min(map[u][v],w);
    }
    cout<<"请输入小明所在的位置"<<endl;
    cin>>st;
    Dijkstra(st);
    cout<<"小明所在的位置："<<st<<endl;
    for(int i=1;i<=n;i++){
        cout<<"小明："<<st<<"---->"<<"要去的位置："<<i;
        if(dist[i]==INF){
            cout<<"到不到"<<endl;
        }else
            cout<<"最短距离为："<<dist[i]<<endl;
    }
}
