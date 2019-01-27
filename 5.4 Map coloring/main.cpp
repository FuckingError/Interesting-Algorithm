#include <iostream>
#define N 50
using namespace std;

int n,m;//顶点数 边数
int c;//颜色数
int G[N][N];

int sum;//方案总数

int x[N];
/*
2019年1月28日 02点25分
地图着色问题

回溯法:
    Tip：目前我感觉回溯法 适用于选择问题....

注意：
    递归中如果有for循环 循环变量定义为局部变量
*/

//不需要写限界函数 不是求最优值 只要一种解决方案

//1.判断是否可以涂这个颜色
bool ifOk(int t){
    for(int i=1;i<t;i++){
        if(G[t][i]==1&&x[i]==x[t]) return false;// !这里不能用i作为循环变量 因为在Backrack的for循环内嵌套
    }
    return true;
}

//2.回溯
void Backtrack(int t){
    //1.判断t是否<=n
    if(t>n){
        //此时就已经获得了一种解决问题的方案
        sum++;
        //打印该方案
        cout<<"第"<<sum<<"种方案:";
        for(int i=1;i<=n;i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }else{
        //有三种涂色方案
        for(int i=1;i<=c;i++){
            x[t] = i;// ！在回溯法中 记录选择的数组可以被后面的选择覆盖 所以不用担心
            if(ifOk(t))
                Backtrack(t+1);
        }
    }
}

int main()
{
    int u,v;//相邻顶点
    cout << "输入顶点数" << endl;
    cin>>n;
    cout << "输入颜色数" << endl;
    cin>>c;
    cout << "输入边数" << endl;
    cin>>m;

    for(int i=1;i<=m;i++){
        cin>>u>>v;
        G[u][v] = 1;
        G[v][u] = 1;
    }

    Backtrack(1);
    return 0;
}
