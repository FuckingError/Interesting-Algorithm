#include <iostream>
#include <cstring>
#include <queue>
/*
2018��10��7�� 20:27:47
ʹ���ڽӱ�

��̼��ɣ�
    1.Ϊ�����ʼ�� Ŀǰ��˵ ��ʼ��0������memset  ƫ������ݻ�����forѭ��
*/
using namespace std;

const int N = 100;//�������
const int INF = 1e7;
int dist[N],n,m;
bool flag[N];

struct Node{//����
    int v;//���
    int w;//Ȩֵ
    Node *next;
};

struct Hnode{//����
    Node *first;
};

Hnode g[N];

//����һ����
void insertedge(Hnode &p,int x,int y){
    Node *q = new Node;// ! ʹ�ö�̬�ڴ������ڴ�ռ���Ҫ�ֶ��ͷ�
    q->v = x;
    q->w = y;
    //�½������ͷ������ ԭ���Ľ�������½�����
    q->next = p.first;
    p.first = q;
}

//����
Node* findNode(int v1,int v2){
    Node *cur = g[v1].first;
    while(cur){
        if(cur->v==v2)
            break;
        cur = cur->next;
    }
    return cur;

}

struct Node_Queue{
    int u,step;//u�Ƕ��� step�ǵ�ǰ��̾���
    Node_Queue(){};
    Node_Queue(int a,int st){//���캯��
        u = a;
        step = st;
    }
    bool operator < (const Node_Queue& a)const{//���� ʹ������ �������β� ���������еı�������һ��  ���õĻ��������������б�������
        return step>a.step;  // �� �����ǰ�ڵ�a.step����b.step���� ��a<b����(���ȶ��дӴ�С����) Ҳ����b���� a����
    }
};

void dijkstra(int st){
    //��ʼ������
    memset(flag,0,sizeof(flag));
    for(int i=1;i<=n;i++){//��ʼ��Dist
        dist[i] = INF;
    }

    dist[st] = 0;

    priority_queue<Node_Queue> Q;//���ȶ���
    Q.push(Node_Queue(st,0));
    while(!Q.empty()){
        Node_Queue it = Q.top();//ѡ����С��  ���ȶ�������������С��
        Q.pop();
        int t = it.u;
        if(flag[t])
            continue;
        flag[t] = 1;//��v-s�и������Դ������ĵ����s
        Node *n = g[t].first;
        while(n){
            int num = n->v;
            if(!flag[num]){
                Node* t_num = findNode(t,num);
                if(dist[num]>dist[t]+t_num->w){
                    dist[num] = dist[t]+t_num->w;//����dist
                    Q.push(Node_Queue(num,dist[num]));
                }
            }
            n = n->next;
        }
    }
}

int main()
{
    int u,v,w,st = 0;
    cout<<"��������ͱߵ�����"<<endl;
    cin>>n>>m;
    cout<<"����֮���·�ߺ;���"<<endl;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        insertedge(g[u],v,w);
    }
    cout<<"��ʲô�ط�������"<<endl;
    cin>>st;
    dijkstra(st);
    for(int i=1;i<=n;i++){
        cout<<"��"<<i<<"����Ϊ��"<<dist[i]<<endl;;
    }
    return 0;

}
