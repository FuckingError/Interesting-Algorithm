#include <iostream>
#include <queue>
/*
数据结构:
    邻接表 -> 存储图
        顶点数组
        链表
    数组closest -> 记录最小生成树中距离该点最近的点
    数组lowcost -> 记录距离
    数组flag    -> 判断是否已经加入最小生成树
    优先队列    -> 每次弹出距离最小生成树最近的点和距离
*/

using namespace std;

const int INF = 0x3fffffff;//最大距离
const int N = 100;//最大顶点数
bool flag[N];

int closest[N];
int lowcost[N];

//优先队列的结点
struct PNode{
    int index;
    int lowcost;
    PNode(){};
    PNode(int i,int l){
        index = i;
        lowcost = l;
    }
    bool operator <(const PNode& node)const{
        return lowcost > node.lowcost;
    }
};

//邻接表

//结点
struct Node{
    int v;//编号
    int w;//权值
    Node* next;
};
//顶点
struct HNode{
    Node* first;
    HNode(){
        first = 0;//指针初始化
    }
};

HNode h[N];

//插入一条边
void insertEdge(HNode& hNode,int v,int w){
    Node *node = new Node;
    node->v = v;
    node->w = w;
    node->next = hNode.first;
    hNode.first = node;
}

//查找
Node* findNode(int v1,int v2){
    Node *cur = h[v1].first;
    while(cur){
        if(cur->v==v2)
            break;
        cur = cur->next;
    }
    return cur;
}

void Prime(int n,int u0){
    //定义初始化优先队列
    priority_queue<PNode> Q;
    //初始化 closest 和 lowcost flag
    for(int i=1;i<=n;i++){
        if(i!=u0){
            closest[i] = u0;
            if(findNode(u0,i)){
                lowcost[i] = findNode(u0,i)->w;
                flag[i] = false;

                Q.push(PNode(i,lowcost[i]));
            }
            else lowcost[i] = INF;
        }else{
            lowcost[i] = 0;
            flag[i] = true;
        }
    }
    //选出在最小生成树之外的 最小距离的点
    while(!Q.empty()){
        PNode p = Q.top();
        //delete &Q.top();
        Q.pop();
        if(flag[p.index]) continue;
        flag[p.index] = true;
        Node *node = h[p.index].first;
        while(node){
            //更新lowcost closet
            if((!flag[node->v])&&((node->w)<lowcost[node->v])){
                lowcost[node->v] = node->w;
                closest[node->v] = p.index;
                Q.push(PNode(node->v,lowcost[node->v]));
            }
            node = node->next;
        }
    }
}

int main()
{
    int n,m,u0,u,v,w,sumcost=0;
    cout<<"请输入顶点个数和边数"<<endl;
    cin>>n>>m;
    cout<<"请输入结点数u,v和边值w"<<endl;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        insertEdge(h[u],v,w);
        insertEdge(h[v],u,w);//无向图
    }
    cout<<"输入任意结点u0:"<<endl;
    cin>>u0;
    Prime(n,u0);
    cout<<"数组lowcost的内容是:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<lowcost[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        sumcost += lowcost[i];
    }
    cout<<"最小花费为"<<sumcost<<endl;
    return 0;
}
