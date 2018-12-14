#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
注意类型名
结构体初始化不要写错
2018年10月8日 17:09:52
//动态数组vector的使用
    push_back()
    clear()
    size()   注意此时返回值是unsigned的整型 如果for循环则不要int i = 0; 而是vector<>::size_type i = 0;
*/

const int MAXVALUE=10000;
const int MAXLEAF=30;
const int MAXNODE=MAXLEAF*2-1;

//树的结构体
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

//优先队列结构体
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

//定义树
HNodeType HuffNode[MAXNODE];
HCodeType HuffCode[MAXLEAF];

void HuffmanTree(HNodeType HuffNode[MAXNODE],int n){
    //初始化
    for(int i=0;i<2*n-1;i++){
        HuffNode[i].parent = -1;
        HuffNode[i].rchild = -1;
        HuffNode[i].lchild = -1;
        HuffNode[i].weight = 0;
    }
    //定义优先队列结构体
    priority_queue<Node> Q;

    //输入数据 并 放入优先队列中
    cout<<"请输入叶子结点的值和权值"<<endl;;
    for(int i=0;i<n;i++){
        cin>>HuffNode[i].value>>HuffNode[i].weight;
        Q.push(Node(i,HuffNode[i].weight));
    }
    //进行n-1次合并 每次选出两个最小的权值
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
        //start初始化为n
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
