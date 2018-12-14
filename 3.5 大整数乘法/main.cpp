#include <iostream>
#include <cstring>
/*
2018年10月13日 14:23:02
当对对数组的操作时 注意 元素位数 等于 要不要写

编程技巧: 右移
*/
using namespace std;
#define M 100
char sa[1000];
char sb[1000];
//存储大整数的结构体
typedef struct _Node{
    int s[M];
    int l;//字符串长度
    int c;//进位
}Node,*pNode;

//分解
void cp(pNode src,pNode des,int st,int l){//从st开始 取l个数  取出后面一半放入新的结构体中
    int i,j;
    for(i=st,j=0;i<st+l;i++,j++){
        des->s[j] = src->s[i];
    }
    des->l = l;
    des->c = st+src->c; //des次幂 等于开始取数的位置加上src次幂
}

void add(pNode pa,pNode pb,pNode ans){
    int cc,k,len,alen,blen;
    int ta,tb,i;
    pNode temp;
    //保证a的次幂大
    if((pa->c<pb->c)){
        temp = pa;
        pa = pb;
        pb = temp;
    }
    //结果的次幂为两个数中的小的次幂 比如   2100    结果是两个数中 小的次幂
    //                                   3260000
    ans->c = pb->c;
    cc = 0;//进位初始化为0
    k = pa->c-pb->c;//a左侧需要补的0   00|00623
                  //                   00|12
    //算出结果的长度
    alen = pa->l+pa->c;
    blen = pb->l+pb->c;
    len = alen>blen?alen:blen;//长的给总长度
    //此时 需要计算的部分的长度就可以求出来了  结果次幂部分不参与计算
    len = len-ans->c;

    //进行相加计算
    for(i=0;i<len;i++){
        //从a中取数
        if(i<k)//k为a左侧需要补零的个数
            ta = 0;
        else
            ta = pa->s[i-k];//当i=k时，补零结束 此时取出a中第0位数字
        //从b中取数
        if(i<pb->l)
            tb = pb->s[i];
        else //当超出b数组中的长度 就需要在b右侧补零了
            tb = 0;
        if(i>=pa->l+k)//如果a数字先取完，a右侧补零  错误！等号啊
            ta = 0;

        //同位相加
        ans->s[i] = (ta+tb+cc)%10;//记录两位之和的个位数
        cc = (ta+tb+cc)/10;//得出应该进几位
    }
    if(cc){
        ans -> s[i++] = cc;//如果最后一位计算表完毕 还能进位 则进位
    }//这儿i++  因为i比实际长度小1 所以要加1
    ans->l = i;
}

void mul(pNode pa,pNode pb,pNode ans){
    Node ah,al,bh,bl;//这样的话 不用自己开辟内存空间
    int ma = pa->l>>1;//长度除以2
    int mb = pb->l>>1;
    pNode temp;
    int cc,w,i;//cc进位  w存放pa（pa是一位）
    Node t1,t2,t3,t4,z;//存放相乘后的结果 还需要一个z用来暂时存放第二次相加后的结果

    //分解结束的判断  a 或 b长度为1 此时 ma mb为0
    //分解结束 开始治理 做乘法
    //如果不分解到最后是不会进行相乘操作的
    if(!ma||!mb){
        //pa 大于等于pb
        if(!ma){
            temp = pa;
            pa = pb;
            pb = temp;
        }
        ans->c = pa->c + pb->c;
        //做乘法
        w = pb->s[0];//此时p只有一位
        cc = 0;
        for(i=0;i<pa->l;i++){
            ans->s[i] = (w*pa->s[i]+cc)%10;
            cc = (w*pa->s[i]+cc)/10;//处理进位
        }
        if(cc) ans->s[i++] = cc;
        ans->l = i;
        return;
    }

    //分解
    cp(pa,&ah,ma,pa->l-ma);
    cp(pa,&al,0,ma);
    cp(pb,&bh,mb,pb->l-mb);
    cp(pb,&bl,0,mb);

    //分成四个部分相乘
    mul(&ah,&bh,&t1);
    mul(&ah,&bl,&t2);
    mul(&al,&bh,&t3);
    mul(&al,&bl,&t4);

    //相加
    add(&t3,&t4,ans);
    add(&t2,ans,&z);
    add(&t1,&z,ans);
}

int main()
{
    Node ans,a,b;
    cout<<"输入大整数a:"<<endl;
    cin>>sa;
    cout<<"输入大整数b:"<<endl;
    cin>>sb;
    a.l = strlen(sa);
    b.l = strlen(sb);
    int z=0,i;
    for(i=a.l-1;i>=0;i--){
        a.s[z++] = sa[i]-'0';
    }
    a.c = 0;
    z=0;
    for(i=b.l-1;i>=0;i--){
        b.s[z++] = sb[i]-'0';
    }
    b.c = 0;
    mul(&a,&b,&ans);
    cout<<"结果为:"<<endl;
    for(i=ans.l-1;i>=0;i--){
        cout<<ans.s[i];
    }
    cout<<endl;
    return 0;
}
