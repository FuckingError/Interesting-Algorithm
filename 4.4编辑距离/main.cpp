#include <iostream>
#include <cstring>

/*
2018年10月18日 21:05:20
两个字符串
一共三种操作： 删去 插入 替换
dp[i][j] = min{dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+diff} diff=0 当d[i-1]==d[j-1] 1

！ 对数组的操作 一定要注意 是否有等号啊
*/
using namespace std;
const int N = 100;
char str1[N],str2[N];
int d[N][N]; //编辑距离  数组内的前面每一个元素的值都是 此时字符串对应相等时的操作

int min(int a,int b){
    return a<b?a:b; //返回较小的值
}

int editdistance(char *str1,char *str2){
    int len1 = strlen(str1);//字符串长度
    int len2 = strlen(str2);
    //初始化第一行 第一列
    for(int i=0;i<=len1;i++)
        d[i][0] = i;
    for(int j=0;j<=len2;j++)  //！！！对数组的操作 一定要注意 是否有等号啊
        d[0][j] = j;
    for(int i=1;i<=len1;i++){
        for(int j=1;j<len2;j++){
            int diff;
            diff = str1[i-1]==str2[j-1]?0:1;
            int temp = min(d[i-1][j]+1,d[i][j-1]+1);
            d[i][j] = min(temp,d[i-1][j-1]+diff);
        }
    }
    return d[len1][len2];
}

int main()
{
    cout<<"输入字符串str1:"<<endl;
    cin>>str1;
    cout<<"输入字符串str2:"<<endl;
    cin>>str2;
    cout<<str1<<"和"<<str2<<"的距离为："<<editdistance(str1,str2);
    return 0;
}
