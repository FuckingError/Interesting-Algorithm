#include <iostream>
#include <cmath>
#define N 105
using namespace std;
int n;
int sum;//方案数
int x[N];//方案  每一行的第几格
/*
2019年1月28日 03点38分
n皇后问题

绝对值函数 fabs  cmath中
*/


bool ifPlace(int t){//判断当前格子是否可以放置
    for(int i=1;i<t;i++){
        if(x[i]==x[t]||(t-i)==fabs(x[t]-x[i])) return false;
    }
    return true;
}


void Backtrack(int t){
    if(t>n){
        sum++;
        cout<<"方案"<<sum<<":";
        for(int i=1;i<=n;i++)
            cout<<x[i]<<" ";
        cout<<endl;
    }else{
        for(int i=1;i<=n;i++){
            x[t] = i;
            if(ifPlace(t))
                Backtrack(t+1);
        }
    }
}

int main()
{
    cout << "皇后个数" << endl;
    cin >> n;
    Backtrack(1);
    return 0;
}
