#include <iostream>
#include <windows.h>
#include <stack>
/*
2018年9月24日 14:39:15
算法：Dijkstra 单源最短路径算法
算法基本思想：
    1.首先假定一个源点，将所有顶点V 分为S（S中的顶点到源点的最短路径已经确定），V-S（还未确定）
    2.将从源点出发，只经过S中的顶点，到达V-S中的某个顶点的路径称为 特殊路径
    3.将到达V-S中的 最短 特殊路径 存入dist数组中
    4.更新dist 将V-S中的顶点借助该特殊路径缩小后的路径长度写入dist

    重复3 4直到V-S为空

数据结构：
    邻接矩阵
    dist
    p

复杂度：n²

算法策略：贪心策略
        体现在：第三步 先从源点出发求出一条最短路径，再参照该最短路径，求出长度次短的一条路径，直到求出从源点到其他各点的最短路径
编程技巧：
    1.<windows.h> 中的system("color ")调颜色
    2.邻接表表示图
    3.<stack> 中的栈
*/

using namespace std;
const int N =100;//城市个数  先写这个是为了初始化map dist p
const int INF = 1e7; //无穷大为10000000
int map[N][N],dist[N],p[N],n,m;//n为城市的个数 m为城市间路线的条数  map带权邻接矩阵 用于存储图 dist用于存储 各点到源点的最短距离 p用于存储上一个点
bool flag[N]; //如果flag[i]等于true 说明点i已经加入了集合s，否则顶点i属于集合v-s

void Dijkstra(int u){  //迪科斯彻
    //初始化dist 各点到u的最短距离 flag
    for(int i=1;i<=n;i++){  //map中行与列都是从1开始的
        dist[i] = map[u][i];
        flag[i] = false;
        if(dist[i]!=INF) //如果dist[i]中不等于INF 则p存储下i点的前驱
            p[i] = u;
        else
            p[i] = -1;
    }
    //初始化集合S
    dist[u] = 0;//将源点设置为0
    flag[u] = true;//初始时，集合s中只有源点u

    for(int j=1;j<=n;j++){ //因为要将n-1个点放入S中 所以要循环n-1次

        //在V-S中寻找距离源点u最近的顶点t
        int temp = INF,t = u;//t就是V-S中距离源点最近的点，初始化为u
        for(int i=1;i<=n;i++){
            if(!flag[i]&&dist[i]<temp){
                t = i;//得到当前距离源点最近的点
                temp = dist[i];//将当前最短距离赋值给temp  继续循环比较 最终得出最小值
            }
        }
        //判断是否找到除源点外的最短距离的点   函数出口
        if(t==u) return;

        //如果找到的话 将该点放入S
        flag[t] = true;

        //更新dist p
        for(int i = 1;i<=n;i++){
            //更新dist 如果V-S中的 【与t点相邻的】 某一点借助t点 离源点更短 则更新dist p
            if(!flag[i]&&map[t][i]<INF){ //判断i点是否在V-S中 并且与t点相邻
                if((dist[t]+map[t][i])<dist[i]){       //判断是否借助t点 离源点更短
                    dist[i] = dist[t]+map[t][i];
                    p[i] = t;
                }
            }
        }
    }
}

//显示路径
void findPath(int u){
    int x;
    stack<int>s;//C++自带的函数创建一个栈
    cout<<"源点为:"<<u<<endl;

    for(int i=1;i<=n;i++){ //依次列出源点到各顶点的路线
        x=p[i];//取出终点
        while(x!=-1){ //从终点 逆向寻找直到找到源点  源点处的p为-1  压入栈中
            s.push(x); //将前驱依次压入栈中
            x=p[x];
        }
        cout<<"源点到其他各顶点最短路径为：";
        while(!s.empty()){//依次取出栈顶元素
            cout<<s.top()<<"--";
            s.pop();//出栈
        }
        cout<<i<<" 最短距离为："<<dist[i]<<endl;
    }
}

int main()
{
    int u,v,w,st;
    system("color 0d");
    cout<<"请输入城市的个数"<<endl;
    cin>>n;
    cout<<"请输入城市之间的路线的个数"<<endl;
    cin>>m;
    cout<<"请输入城市之间的路线以及距离"<<endl;
    //初始化map矩阵
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            map[i][j] = INF;//初始化邻接矩阵为无穷大
        }
    }
    while(m--){
        cin>>u>>v>>w;
        map[u][v]=min(map[u][v],w);
    }
    cout<<"输入小明现在所处位置："<<endl;
    cin>>st;
    Dijkstra(st);
    for(int i=1;i<=n;i++){
        cout<<"小明: "<<st<<" - "<<"要去的位置"<<i<<endl;
        if(dist[i] == INF)
            cout<<"sorry,无路可达"<<endl;
        else
            cout<<"最短距离为："<<dist[i]<<endl;
    }
    findPath(st);
    return 0;
}
