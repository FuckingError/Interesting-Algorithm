#include <iostream>
/*
2018��10��19�� 11:34:29
�� 4.5��ͧ��������
*/
using namespace std;
const int msize = 100;
int p[msize]; //��¼��������
int m[msize][msize],s[msize][msize];
int n;//�������

void matrixchain(){
    int i,j,r,k; //�����k �Ǿ������ķָ��
    //�ֽ����� �ӹ�ģ2 ����ģn
    for(r=2;r<=n;r++){
        for(i=1;i<=n-r+1;i++){
            j = i+r-1;//�ó�j��i�Ĺ�ϵ
            //����һ�ⲻͬ���� ����k��i��ʼ  ��һ���Ǵ�i+1��ʼ
            //����һ����ͬ�� ��һ���ʼ�������� m[i][j]���ɳ�ʼֵ�� ����һ��û ������һ������i��ͷ������ ���������� �������ѭ�� ���бȽ�
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
    //�ݹ�  һֱ���ֵ�һ���� ��ʱi==j
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
    cout<<"���������ĸ���"<<endl;
    cin>>n;
    int i,j;
    cout<<"�������������������һ�����������"<<endl;
    for(i=0;i<=n;i++)
        cin>>p[i];
    matrixchain();
    print(1,n);
    cout<<endl;
    cout<<"��СֵΪ"<<m[1][n]<<endl;
}
