#include <iostream>

using namespace std;
const int INF =0x3fffffff;
const int N = 100;
bool flag[N];//判断是否已经加入最小生成树

int closest[N];
int lowcost[N];//存储在当前最小生成树中 与 该点最近的那个点

void Prime(int n,int u0,int c[N][N]){ //顶点个数n  开始顶点u0 带权邻接矩阵 C[n][n]
    flag[u0] = true;
    int i,j = 0;
    //初s始化操作
    for(i=1;i<=n;i++){
        if(i!=u0){
            closest[i] = u0;
            lowcost[i] = c[u0][i];
            flag[i] = false;
        }else{
            lowcost[i] = 0;
            flag[i] = true;
        }
    }

    //选出最小值 加入最小生成树 更新距离
    for(i=1;i<=n;i++){//将n-1个点加入 因为不知道u0是哪个所以还是循环n次
        int temp = INF;
        int t = u0;
        for(j=1;j<=n;j++){
            if((!flag[j])&&(lowcost[j]<temp)){
                t = j;
                temp = lowcost[j];
            }
        }
        // ！要考虑找不到的情况
        if(t==u0) break;//已经全部放入了最小生成树 flag全为true

        //将找出的最小值 加入最小生成树
        flag[t] = true;
        //更新  遍历邻接矩阵 j行
        for(j=1;j<=n;j++){
            if((!flag[j])&&(c[t][j]<lowcost[j])){
                lowcost[j] = c[t][j];
                closest[j] = t;
            }
        }
    }
}


int main()
{
    int n,c[N][N],m,u,v,w;
    int u0;
    cout<<"输入结点数n和边数m:"<<endl;
    cin>>n>>m;
    int sumcost = 0;
    //初始化
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            c[i][j] = INF;
        }
    }
    cout<<"输入结点数 u,v和边值w："<<endl;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        c[u][v] = c[v][u] = w;
    }
    cout<<"输入任意结点"<<endl;
    cin >> u0;
    Prime(n,u0,c);
    cout<<"数组lowcost的内容为：";
    for(int i=1;i<=n;i++){
        cout<<lowcost[i]<<" ";
        sumcost += lowcost[i];
    }
    cout<<endl;
    cout<<"花费最小值为："<<sumcost<<endl;
    return 0;
}
