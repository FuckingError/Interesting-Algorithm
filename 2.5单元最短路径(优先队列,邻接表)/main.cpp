#include <iostream>
#include <cstring>
#include <queue>
/*
2018年10月7日 20:27:47
使用邻接表

编程技巧：
    1.为数组初始化 目前来说 初始化0可以用memset  偏大的数据还是用for循环
*/
using namespace std;

const int N = 100;//顶点个数
const int INF = 1e7;
int dist[N],n,m;
bool flag[N];

struct Node{//表结点
    int v;//编号
    int w;//权值
    Node *next;
};

struct Hnode{//顶点
    Node *first;
};

Hnode g[N];

//插入一条边
void insertedge(Hnode &p,int x,int y){
    Node *q = new Node;// ! 使用动态内存分配的内存空间需要手动释放
    q->v = x;
    q->w = y;
    //新结点连到头结点后面 原来的结点连在新结点后面
    q->next = p.first;
    p.first = q;
}

//查找
Node* findNode(int v1,int v2){
    Node *cur = g[v1].first;
    while(cur){
        if(cur->v==v2)
            break;
        cur = cur->next;
    }
    return cur;

}

struct Node_Queue{
    int u,step;//u是顶点 step是当前最短距离
    Node_Queue(){};
    Node_Queue(int a,int st){//构造函数
        u = a;
        step = st;
    }
    bool operator < (const Node_Queue& a)const{//参数 使用引用 参数是形参 主调函数中的变量复制一份  引用的话就是主调函数中变量本身
        return step>a.step;  // ！ 如果当前节点a.step大于b.step成立 则a<b成立(优先队列从大到小排列) 也就是b在上 a在下
    }
};

void dijkstra(int st){
    //初始化操作
    memset(flag,0,sizeof(flag));
    for(int i=1;i<=n;i++){//初始化Dist
        dist[i] = INF;
    }

    dist[st] = 0;

    priority_queue<Node_Queue> Q;//优先队列
    Q.push(Node_Queue(st,0));
    while(!Q.empty()){
        Node_Queue it = Q.top();//选出最小的  优先队列最上面是最小的
        Q.pop();
        int t = it.u;
        if(flag[t])
            continue;
        flag[t] = 1;//将v-s中各点距离源点最近的点加入s
        Node *n = g[t].first;
        while(n){
            int num = n->v;
            if(!flag[num]){
                Node* t_num = findNode(t,num);
                if(dist[num]>dist[t]+t_num->w){
                    dist[num] = dist[t]+t_num->w;//更新dist
                    Q.push(Node_Queue(num,dist[num]));
                }
            }
            n = n->next;
        }
    }
}

int main()
{
    int u,v,w,st = 0;
    cout<<"顶点个数和边的条数"<<endl;
    cin>>n>>m;
    cout<<"城市之间的路线和距离"<<endl;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        insertedge(g[u],v,w);
    }
    cout<<"从什么地方出发？"<<endl;
    cin>>st;
    dijkstra(st);
    for(int i=1;i<=n;i++){
        cout<<"点"<<i<<"距离为："<<dist[i]<<endl;;
    }
    return 0;

}
