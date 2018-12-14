#include <iostream>
#include <queue>
#include <cstring>
#include <windows.h>
/*
2018��10��6�� 17:44:34
ʹ�����ȶ��� ���͸��Ӷȣ�������ѡ����ǰv-s�о���s�����·����

��̼��ɣ�
    1.struct �п���ʹ�ù��캯��
    2.���� �Ƚ������
    3.���ȶ���
    4.���� ��ʼ������ memset

*/
using namespace std;
const int N = 100;//��������
const int INF = 1e7;//�����
int map[N][N],dist[N],n,m;
bool flag[N];

struct Node{
    int u,step;//u�Ƕ��� step�ǵ�ǰ��̾���
    Node(){};
    Node(int a,int st){//���캯��
        u = a;
        step = st;
    }
    bool operator < (const Node& a)const{//���� ʹ������ �������β� ���������еı�������һ��  ���õĻ��������������б�������
        return step>a.step;  // �� �����ǰ�ڵ�a.step����b.step���� ��a<b����(���ȶ��дӴ�С����) Ҳ����b���� a����
    }
};

void Dijkstra(int st){
    priority_queue <Node> Q;//���ȶ���
    Q.push(Node(st,0));
    //��ʼ������
    memset(flag,0,sizeof(flag)); //flag�����ʼ��Ϊ0
    for(int i=1;i<=n;i++){//��ʼ��Dist
        dist[i] = INF;
    }
    dist[st] = 0;
    while(!Q.empty()){
        Node it = Q.top();//��ͷ���ж�ͷԪ��Ϊ��Сֵ
        Q.pop();
        int t = it.u;
        if(flag[t])//˵���Ѿ��ҵ�����̾��� �ý���Ƕ���������ظ�Ԫ��  ���磺Դ�� �յ���ͬһ��  ���о��Ǻ����������������Ԫ�� �����ظ�
            continue;
        //����dist
        flag[t] = 1;
        for(int i=1;i<=n;i++){
            if(!flag[i]&&map[t][i]<INF){// �ж��뵱ǰ���й�ϵ�ĵ� �����Լ����ܵ��Լ�
                if(dist[i]>dist[t]+map[t][i]){
                    dist[i] = dist[t]+map[t][i];
                    Q.push(Node(i,dist[i]));//�����ظ���Ԫ��
                }
            }
        }
    }
}

int main()
{
    int u,v,w,st;
    system("color 0d");
    cout<<"��������и���"<<endl;
    cin>>n;
    cout<<"���������֮���·�ߵĸ���"<<endl;
    cin>>m;
    for(int i=1;i<=n;i++){//��ʼ���ڽӾ���
        for(int j=1;j<=n;j++){
            map[i][j] = INF;
        }
    }
    cout<<"���������֮��u,v��·���Լ�����w:"<<endl;
    while(m--){
        cin>>u>>v>>w;
        map[u][v]=min(map[u][v],w);
    }
    cout<<"������С�����ڵ�λ��"<<endl;
    cin>>st;
    Dijkstra(st);
    cout<<"С�����ڵ�λ�ã�"<<st<<endl;
    for(int i=1;i<=n;i++){
        cout<<"С����"<<st<<"---->"<<"Ҫȥ��λ�ã�"<<i;
        if(dist[i]==INF){
            cout<<"������"<<endl;
        }else
            cout<<"��̾���Ϊ��"<<dist[i]<<endl;
    }
}
