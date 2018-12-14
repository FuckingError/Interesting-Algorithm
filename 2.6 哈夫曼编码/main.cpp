#include <iostream>
/*
2018��10��7�� 22:41:50
���ݽṹ�����ı�ʾ
*/
using namespace std;

const int MAXBIT = 100;
const int MAXVALUE = 1000;
const int MAXLEAF = 30;
const int MAXNODE = MAXLEAF*2-1; //�����ڵ���n��ʱ���ܹ����Ϊ2*n-1  n-1�˺ϲ���ÿ�κϲ�����һ���½�� ������ 2n-1

typedef struct{
    double weight;
    int parent;
    int lchild;
    int rchild;
    char value;
}HNodeType;//���ṹ��

typedef struct{
    int bit[MAXBIT];
    int start;
}HCodeType;//����ṹ��

//����ṹ������
HNodeType HuffNode[MAXNODE];
HCodeType HuffCode[MAXLEAF];

//���������
void HuffmanTree(HNodeType HuffCode[MAXLEAF],int n){
    int x1,x2;
    double m1,m2;
    //��ʼ������
    for(int i=0;i<2*n-1;i++){
        HuffCode[i].parent = -1;
        HuffCode[i].lchild = -1;
        HuffCode[i].rchild = -1;
        HuffCode[i].weight = 0;
    }
    //����n��Ҷ�ӽڵ��Ȩֵ
    cout<<"���������Ȩֵ"<<endl;
    for(int i=0;i<n;i++){
        cin>>HuffNode[i].value>>HuffNode[i].weight;
    }
    //����n-1�κϲ� ÿ���ҳ���С������ֵ
    for(int i=0;i<n-1;i++){
        m1=m2=MAXVALUE;
        x1=x2=-1;
        //�����Ѿ�����ֵ����������Ԫ�� (��Ϊ�޷�������Щ��Ҷ�ӽ��ͺ����ϲ����Ľ��)
        for(int j=0;j<n+i;j++){
            if(HuffNode[j].parent==-1){
                if(HuffNode[j].weight<m1){
                    m2 = m1;//�����˱�m1С����  ���԰ѵڶ�С�ĸ�m2
                    x2 = x1;
                    m1 = HuffNode[j].weight;
                    x1 = j;
                }else if(HuffNode[j].weight<m2){
                    m2 = HuffNode[j].weight;
                    x2 = j;
                }
            }
        }
        //�ϲ����������
        HuffNode[x1].parent = n+i;
        HuffNode[x2].parent = n+i;
        HuffNode[n+i].weight = m1+m2;
        HuffNode[n+i].lchild = x1;
        HuffNode[n+i].rchild = x2;
        cout<<"x1.weight and x2.weight in round"<<i+1<<"\t"<<HuffNode[x1].weight<<"\t"<<HuffNode[x2].weight<<endl;//����
    }
}

//������������
void HuffmanCode(HCodeType HuffCode[MAXLEAF],int n){
    HCodeType cd;//����һ����ʱ�������������ʱ����Ϣ
    int p,c;
    for(int i=0;i<n;i++){
        cd.start = n-1;//��n-1�ĵط���ʼ��� ��һ����ǰ��һ��
        c = i;
        p = HuffNode[i].parent;
        while(p != -1){
            if(HuffNode[p].lchild==c){
                cd.bit[cd.start] = 0;//��Ϊ0 ��Ϊ1
            }else{
                cd.bit[cd.start] = 1;
            }
            cd.start--;//��ǰ��һ��
            c = p;
            p = HuffNode[c].parent;
        }
        for(int j=cd.start+1;j<n;j++){
            HuffCode[i].bit[j] = cd.bit[j];
        }
        HuffCode[i].start = cd.start;
    }
}

int main()
{
    int i,j,n;
    cout<<"Please input n:"<<endl;
    cin>>n;
    HuffmanTree(HuffNode,n);
    HuffmanCode(HuffCode,n);
    //���
    for(i=0;i<n;i++){
        cout<<HuffNode[i].value<<":Huffman code is:";
        for(j=HuffCode[i].start+1;j<n;j++){
            cout<<HuffCode[i].bit[j];
        }
        cout<<endl;
    }
    return 0;
}
