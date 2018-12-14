#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
ע��������
�ṹ���ʼ����Ҫд��
2018��10��8�� 17:09:52
//��̬����vector��ʹ��
    push_back()
    clear()
    size()   ע���ʱ����ֵ��unsigned������ ���forѭ����Ҫint i = 0; ����vector<>::size_type i = 0;
*/

const int MAXVALUE=10000;
const int MAXLEAF=30;
const int MAXNODE=MAXLEAF*2-1;

//���Ľṹ��
typedef struct{
    double weight;
    int parent;
    int lchild;
    int rchild;
    char value;
}HNodeType;

typedef struct{
    vector<int> bit;
}HCodeType;

//���ȶ��нṹ��
struct Node{
    int num;
    double weight;
    Node(int n,double w){
        num = n;
        weight = w;
    }
    bool operator < (const Node &node)const{
        return weight>node.weight;
    }
};

//������
HNodeType HuffNode[MAXNODE];
HCodeType HuffCode[MAXLEAF];

void HuffmanTree(HNodeType HuffNode[MAXNODE],int n){
    //��ʼ��
    for(int i=0;i<2*n-1;i++){
        HuffNode[i].parent = -1;
        HuffNode[i].rchild = -1;
        HuffNode[i].lchild = -1;
        HuffNode[i].weight = 0;
    }
    //�������ȶ��нṹ��
    priority_queue<Node> Q;

    //�������� �� �������ȶ�����
    cout<<"������Ҷ�ӽ���ֵ��Ȩֵ"<<endl;;
    for(int i=0;i<n;i++){
        cin>>HuffNode[i].value>>HuffNode[i].weight;
        Q.push(Node(i,HuffNode[i].weight));
    }
    //����n-1�κϲ� ÿ��ѡ��������С��Ȩֵ
    for(int i=0;i<n-1;i++){
        int x1,x2;
        double m1,m2=0;
        Node node1 = Q.top();
        x1 = node1.num;
        m1 = node1.weight;
        Q.pop();
        Node node2 = Q.top();
        x2 = node2.num;
        m2 = node2.weight;
        Q.pop();

        HuffNode[n+i].weight = m1+m2;
        HuffNode[n+i].lchild = x1;
        HuffNode[n+i].rchild = x2;
        HuffNode[x1].parent = n+i;
        HuffNode[x2].parent = n+i;

        Q.push(Node(n+i,m1+m2));
    }
}


void HuffmanCode(HCodeType HuffCode[MAXLEAF],int n){
    HCodeType cd;
    int p,c,index = 0;
    for(int i=0;i<n;i++){
        //start��ʼ��Ϊn
        c = i;
        p = HuffNode[i].parent;
        while(p!=-1){
            if(HuffNode[p].lchild==c) cd.bit.push_back(0);
            else cd.bit.push_back(1);
            c = p;
            p = HuffNode[c].parent;
            index++;
        }
        index = 0;
        for(int j=(cd.bit.size()-1);j>=0;j--){
            HuffCode[i].bit.push_back(cd.bit[j]);
            index++;
        }
        cd.bit.clear();
        index = 0;
    }
}


int main()
{
    int i,n;
    cout<<"please input n:"<<endl;
    cin>>n;
    HuffmanTree(HuffNode,n);
    HuffmanCode(HuffCode,n);
    for(i=0;i<n;i++){
        cout<<HuffNode[i].value<<":Huffman code is:";
        for(vector<int>::size_type j=0;j<HuffCode[i].bit.size();j++)
            cout<<HuffCode[i].bit[j];
        cout<<endl;
    }
}
