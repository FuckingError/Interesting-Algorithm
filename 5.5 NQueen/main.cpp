#include <iostream>
#include <cmath>
#define N 105
using namespace std;
int n;
int sum;//������
int x[N];//����  ÿһ�еĵڼ���
/*
2019��1��28�� 03��38��
n�ʺ�����

����ֵ���� fabs  cmath��
*/


bool ifPlace(int t){//�жϵ�ǰ�����Ƿ���Է���
    for(int i=1;i<t;i++){
        if(x[i]==x[t]||(t-i)==fabs(x[t]-x[i])) return false;
    }
    return true;
}


void Backtrack(int t){
    if(t>n){
        sum++;
        cout<<"����"<<sum<<":";
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
    cout << "�ʺ����" << endl;
    cin >> n;
    Backtrack(1);
    return 0;
}
