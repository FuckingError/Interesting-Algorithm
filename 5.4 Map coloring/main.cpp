#include <iostream>
#define N 50
using namespace std;

int n,m;//������ ����
int c;//��ɫ��
int G[N][N];

int sum;//��������

int x[N];
/*
2019��1��28�� 02��25��
��ͼ��ɫ����

���ݷ�:
    Tip��Ŀǰ�Ҹо����ݷ� ������ѡ������....

ע�⣺
    �ݹ��������forѭ�� ѭ����������Ϊ�ֲ�����
*/

//����Ҫд�޽纯�� ����������ֵ ֻҪһ�ֽ������

//1.�ж��Ƿ����Ϳ�����ɫ
bool ifOk(int t){
    for(int i=1;i<t;i++){
        if(G[t][i]==1&&x[i]==x[t]) return false;// !���ﲻ����i��Ϊѭ������ ��Ϊ��Backrack��forѭ����Ƕ��
    }
    return true;
}

//2.����
void Backtrack(int t){
    //1.�ж�t�Ƿ�<=n
    if(t>n){
        //��ʱ���Ѿ������һ�ֽ������ķ���
        sum++;
        //��ӡ�÷���
        cout<<"��"<<sum<<"�ַ���:";
        for(int i=1;i<=n;i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }else{
        //������Ϳɫ����
        for(int i=1;i<=c;i++){
            x[t] = i;// ���ڻ��ݷ��� ��¼ѡ���������Ա������ѡ�񸲸� ���Բ��õ���
            if(ifOk(t))
                Backtrack(t+1);
        }
    }
}

int main()
{
    int u,v;//���ڶ���
    cout << "���붥����" << endl;
    cin>>n;
    cout << "������ɫ��" << endl;
    cin>>c;
    cout << "�������" << endl;
    cin>>m;

    for(int i=1;i<=m;i++){
        cin>>u>>v;
        G[u][v] = 1;
        G[v][u] = 1;
    }

    Backtrack(1);
    return 0;
}
