#include <iostream>
#include <cstring>

/*
2018��10��18�� 21:05:20
�����ַ���
һ�����ֲ����� ɾȥ ���� �滻
dp[i][j] = min{dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+diff} diff=0 ��d[i-1]==d[j-1] 1

�� ������Ĳ��� һ��Ҫע�� �Ƿ��еȺŰ�
*/
using namespace std;
const int N = 100;
char str1[N],str2[N];
int d[N][N]; //�༭����  �����ڵ�ǰ��ÿһ��Ԫ�ص�ֵ���� ��ʱ�ַ�����Ӧ���ʱ�Ĳ���

int min(int a,int b){
    return a<b?a:b; //���ؽ�С��ֵ
}

int editdistance(char *str1,char *str2){
    int len1 = strlen(str1);//�ַ�������
    int len2 = strlen(str2);
    //��ʼ����һ�� ��һ��
    for(int i=0;i<=len1;i++)
        d[i][0] = i;
    for(int j=0;j<=len2;j++)  //������������Ĳ��� һ��Ҫע�� �Ƿ��еȺŰ�
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
    cout<<"�����ַ���str1:"<<endl;
    cin>>str1;
    cout<<"�����ַ���str2:"<<endl;
    cin>>str2;
    cout<<str1<<"��"<<str2<<"�ľ���Ϊ��"<<editdistance(str1,str2);
    return 0;
}
