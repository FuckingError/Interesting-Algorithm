#include <iostream>
/*
2018��10��19�� 10:45:32

��̬�滮�� �������Ž�������ͨ���ݹ�ʵ�ֵ�  ����ֱ���ɶ�ά����ó�
*/
using namespace std;
const int ms = 1000;
int r[ms][ms],m[ms][ms],s[ms][ms];//��վ�����  ����¼  ·�߼�¼
int n;//һ����n��վ��

void rent(){
    int i,j,k,d;

    //������ ��С��ģ
    for(d=3;d<=n;d++){//�����ģΪ3  ��������
        for(i=1;i<=n-d+1;i++){ //������ i
            j = i+d-1;//�յ�
            for(k=i+1;k<j;k++){//�м�ͣ����k
                int temp = m[i][k]+m[k][j];//��������� �����൱�ڵ���֮ǰ��С��ģ�ļ�¼  �Ͳ���Ҫ�ظ�������  ���ֶ�̬�滮
                if(temp<m[i][j]){
                    m[i][j] = temp;
                    s[i][j] = k;
                }
            }
        }
    }
}

//�ݹ�
void print(int i,int j){
    int k = s[i][j];
    if(k!=0){
        print(i,k);
        cout<<k<<endl;
        print(k,j);
    }
}

int main()
{
   int i,j;
   cout<<"������վ��ĸ���:"<<endl;
   cin>>n;
   cout<<"������վ��֮������:"<<endl;
   for(i=1;i<=n;i++){
    for(j=i+1;j<=n;j++){
        cin>>r[i][j];
        m[i][j] = r[i][j];
    }
   }
   rent();
   cout<<"�������Ϊ:"<<m[1][n]<<endl;
   print(1,n);
   return 0;
}
