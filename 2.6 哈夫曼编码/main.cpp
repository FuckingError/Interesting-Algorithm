#include <iostream>
/*
2018年10月7日 22:41:50
数据结构：树的表示
*/
using namespace std;

const int MAXBIT = 100;
const int MAXVALUE = 1000;
const int MAXLEAF = 30;
const int MAXNODE = MAXLEAF*2-1; //当根节点有n个时，总共结点为2*n-1  n-1此合并，每次合并产生一个新结点 所以是 2n-1

typedef struct{
    double weight;
    int parent;
    int lchild;
    int rchild;
    char value;
}HNodeType;//结点结构体

typedef struct{
    int bit[MAXBIT];
    int start;
}HCodeType;//编码结构体

//定义结构体数组
HNodeType HuffNode[MAXNODE];
HCodeType HuffCode[MAXLEAF];

//构造哈夫曼
void HuffmanTree(HNodeType HuffCode[MAXLEAF],int n){
    int x1,x2;
    double m1,m2;
    //初始化操作
    for(int i=0;i<2*n-1;i++){
        HuffCode[i].parent = -1;
        HuffCode[i].lchild = -1;
        HuffCode[i].rchild = -1;
        HuffCode[i].weight = 0;
    }
    //输入n个叶子节点的权值
    cout<<"请输入结点和权值"<<endl;
    for(int i=0;i<n;i++){
        cin>>HuffNode[i].value>>HuffNode[i].weight;
    }
    //进行n-1次合并 每次找出最小的两个值
    for(int i=0;i<n-1;i++){
        m1=m2=MAXVALUE;
        x1=x2=-1;
        //查找已经填入值的所有数组元素 (因为无法区分哪些是叶子结点和后来合并出的结点)
        for(int j=0;j<n+i;j++){
            if(HuffNode[j].parent==-1){
                if(HuffNode[j].weight<m1){
                    m2 = m1;//出现了比m1小的数  所以把第二小的给m2
                    x2 = x1;
                    m1 = HuffNode[j].weight;
                    x1 = j;
                }else if(HuffNode[j].weight<m2){
                    m2 = HuffNode[j].weight;
                    x2 = j;
                }
            }
        }
        //合并这两个结点
        HuffNode[x1].parent = n+i;
        HuffNode[x2].parent = n+i;
        HuffNode[n+i].weight = m1+m2;
        HuffNode[n+i].lchild = x1;
        HuffNode[n+i].rchild = x2;
        cout<<"x1.weight and x2.weight in round"<<i+1<<"\t"<<HuffNode[x1].weight<<"\t"<<HuffNode[x2].weight<<endl;//测试
    }
}

//哈夫曼树编码
void HuffmanCode(HCodeType HuffCode[MAXLEAF],int n){
    HCodeType cd;//定义一个临时变量存放求解编码时的信息
    int p,c;
    for(int i=0;i<n;i++){
        cd.start = n-1;//从n-1的地方开始存放 放一个往前倒一个
        c = i;
        p = HuffNode[i].parent;
        while(p != -1){
            if(HuffNode[p].lchild==c){
                cd.bit[cd.start] = 0;//左为0 右为1
            }else{
                cd.bit[cd.start] = 1;
            }
            cd.start--;//往前倒一个
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
    //输出
    for(i=0;i<n;i++){
        cout<<HuffNode[i].value<<":Huffman code is:";
        for(j=HuffCode[i].start+1;j<n;j++){
            cout<<HuffCode[i].bit[j];
        }
        cout<<endl;
    }
    return 0;
}
