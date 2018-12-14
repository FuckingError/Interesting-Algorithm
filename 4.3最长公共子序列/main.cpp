#include <iostream>
#include <cstring>
/*
动态规划
*/
using namespace std;

const int N = 1002;
int c[N][N],b[N][N];
char s1[N],s2[N];
int len1,len2;

void LCSL(){
    int i,j;
    for(i=1;i<=len1;i++){
        for(j=1;j<=len2;j++){
            if(s1[i-1]==s2[j-1]){
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 1;
            }else{
                c[i][j] = c[i-1][j]>c[i][j-1]?c[i-1][j]:c[i][j-1];
                b[i][j] = c[i-1][j]>c[i][j-1]?2:3;  //2上 3左
            }
        }
    }
}

//递归
void print(int i,int j){
    if(i==0||j==0) return;
    if(b[i][j]==1){
        print(i-1,j-1);
        cout<<s1[i-1]<<" ";
    }else if(b[i][j]==2){
        print(i-1,j);
    }else if(b[i][j]==3){
        print(i,j-1);
    }
}

int main()
{
    int i,j;
    cin>>s1;
    cin>>s2;
    len1 = strlen(s1);
    len2 = strlen(s2);
    for(i=0;i<=len1;i++){
        c[i][0] = 0;
    }
    for(j=0;j<=len2;j++){
        c[0][j] = 0;
    }
    LCSL();
    cout<<"长度是:"<<b[len1][len2]<<endl;
    print(len1,len2);
    return 0;
}

