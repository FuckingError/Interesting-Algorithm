#include <iostream>
/*
2018年10月19日 11:34:29
与 4.5游艇租赁类似
*/
using namespace std;
const int msize = 100;
int p[msize]; //记录矩阵行列
int m[msize][msize],s[msize][msize];
int n;//矩阵个数

void matrixchain(){
    int i,j,r,k; //这儿的k 是矩阵链的分割点
    //分解问题 从规模2 到规模n
    for(r=2;r<=n;r++){
        for(i=1;i<=n-r+1;i++){
            j = i+r-1;//得出j与i的关系
            //与上一题不同的是 这里k从i开始  上一题是从i+1开始
            //还有一个不同点 上一题初始的数组中 m[i][j]是由初始值的 而这一题没 所以先一个计算i开头的连乘 填入数组中 供后面的循环 进行比较
            m[i][j] = m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j] = i;
            for(k=i+1;k<j;k++){
                int t = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(t<m[i][j]){
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }

        }
    }
}

void print(int i,int j){
    //递归  一直划分到一个数 此时i==j
    if(i==j){
        cout<<"A["<<i<<"]";
        return;
    }
    cout<<"(";
    print(i,s[i][j]);
    print(s[i][j]+1,j);
    cout<<")";
}

int main()
{
    cout<<"请输入矩阵的个数"<<endl;
    cin>>n;
    int i,j;
    cout<<"请输入矩阵的行数和最后一个矩阵的列数"<<endl;
    for(i=0;i<=n;i++)
        cin>>p[i];
    matrixchain();
    print(1,n);
    cout<<endl;
    cout<<"最小值为"<<m[1][n]<<endl;
}
