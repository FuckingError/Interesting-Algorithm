#include <iostream>
#define N 100
using namespace std;
int G[N][N];
int n,m;//n ������ m ����
int i,j;
int x[N];//ǰ���ļ�¼
int cn;//��ǰ����

int bestn;//��¼����ֵ
int bestx[N];//��¼���Ž�
/*
2019��1��28�� 01��13��
��������� ��һ������ͼ���ҳ�������ȫ��ͼ ��ȫ��ͼ������ͼ��ÿ�����㶼����

���ݷ�
    Լ������:
        1.��ǰ��������ͼ����ͼ��Ȼά����ȫ��ͼ
        2.û��ʣ�ඥ��
    �޽�����:
        ��ǰ��ȫ��ͼ�еĶ���+ʣ�ඥ��>��ǰ���ֵ

��ǰһ�� 0-1������...
*/

bool ifPlace(int t){//��ǰ�����Ƿ���Է�����ͼ
    for(i=1;i<t;i++){
        if(x[i]==1&&G[t][i]==0) return false;
    }
    return true;
}

void Backtrack(int t){
     //�ж�t�Ƿ�<=n
    if(t>n){
        bestn = cn;
        for(i=1;i<=n;i++){
            bestx[i] = x[i];
        }
        return;
    }
    if(ifPlace(t)){//���� ������ͼ
        cn++;
        x[t] = 1;
        Backtrack(t+1);
        cn--;
    }

    if(cn+n-t>bestn){//���Ҳ�������ͼ��
        x[t] = 0;
        Backtrack(t+1);
    }
}

int main()
{
    int u,v;//�ߵ���������
    cout<<"�������"<<endl;
    cin >> n;

    cout<<"����"<<endl;
    cin >> m;

    cout<<"�����"<<endl;
    for(i=1;i<=m;i++){
        cin>>u>>v;
        G[u][v] = 1;
        G[v][u] = 1;
    }
    Backtrack(1);
    cout<<"�������Ϊ:"<<bestn<<endl;
    for(i=1;i<=n;i++){
        if(bestx[i]) cout<<i<<" ";
    }
    return 0;
}
