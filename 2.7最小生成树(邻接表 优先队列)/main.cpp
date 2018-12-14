#include <iostream>
#include <queue>
/*
���ݽṹ:
    �ڽӱ� -> �洢ͼ
        ��������
        ����
    ����closest -> ��¼��С�������о���õ�����ĵ�
    ����lowcost -> ��¼����
    ����flag    -> �ж��Ƿ��Ѿ�������С������
    ���ȶ���    -> ÿ�ε���������С����������ĵ�;���
*/

using namespace std;

const int INF = 0x3fffffff;//������
const int N = 100;//��󶥵���
bool flag[N];

int closest[N];
int lowcost[N];

//���ȶ��еĽ��
struct PNode{
    int index;
    int lowcost;
    PNode(){};
    PNode(int i,int l){
        index = i;
        lowcost = l;
    }
    bool operator <(const PNode& node)const{
        return lowcost > node.lowcost;
    }
};

//�ڽӱ�

//���
struct Node{
    int v;//���
    int w;//Ȩֵ
    Node* next;
};
//����
struct HNode{
    Node* first;
    HNode(){
        first = 0;//ָ���ʼ��
    }
};

HNode h[N];

//����һ����
void insertEdge(HNode& hNode,int v,int w){
    Node *node = new Node;
    node->v = v;
    node->w = w;
    node->next = hNode.first;
    hNode.first = node;
}

//����
Node* findNode(int v1,int v2){
    Node *cur = h[v1].first;
    while(cur){
        if(cur->v==v2)
            break;
        cur = cur->next;
    }
    return cur;
}

void Prime(int n,int u0){
    //�����ʼ�����ȶ���
    priority_queue<PNode> Q;
    //��ʼ�� closest �� lowcost flag
    for(int i=1;i<=n;i++){
        if(i!=u0){
            closest[i] = u0;
            if(findNode(u0,i)){
                lowcost[i] = findNode(u0,i)->w;
                flag[i] = false;

                Q.push(PNode(i,lowcost[i]));
            }
            else lowcost[i] = INF;
        }else{
            lowcost[i] = 0;
            flag[i] = true;
        }
    }
    //ѡ������С������֮��� ��С����ĵ�
    while(!Q.empty()){
        PNode p = Q.top();
        //delete &Q.top();
        Q.pop();
        if(flag[p.index]) continue;
        flag[p.index] = true;
        Node *node = h[p.index].first;
        while(node){
            //����lowcost closet
            if((!flag[node->v])&&((node->w)<lowcost[node->v])){
                lowcost[node->v] = node->w;
                closest[node->v] = p.index;
                Q.push(PNode(node->v,lowcost[node->v]));
            }
            node = node->next;
        }
    }
}

int main()
{
    int n,m,u0,u,v,w,sumcost=0;
    cout<<"�����붥������ͱ���"<<endl;
    cin>>n>>m;
    cout<<"����������u,v�ͱ�ֵw"<<endl;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        insertEdge(h[u],v,w);
        insertEdge(h[v],u,w);//����ͼ
    }
    cout<<"����������u0:"<<endl;
    cin>>u0;
    Prime(n,u0);
    cout<<"����lowcost��������:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<lowcost[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        sumcost += lowcost[i];
    }
    cout<<"��С����Ϊ"<<sumcost<<endl;
    return 0;
}
