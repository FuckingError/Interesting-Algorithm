#include <iostream>
#include <cstring>
/*
2018��10��13�� 14:23:02
���Զ�����Ĳ���ʱ ע�� Ԫ��λ�� ���� Ҫ��Ҫд

��̼���: ����
*/
using namespace std;
#define M 100
char sa[1000];
char sb[1000];
//�洢�������Ľṹ��
typedef struct _Node{
    int s[M];
    int l;//�ַ�������
    int c;//��λ
}Node,*pNode;

//�ֽ�
void cp(pNode src,pNode des,int st,int l){//��st��ʼ ȡl����  ȡ������һ������µĽṹ����
    int i,j;
    for(i=st,j=0;i<st+l;i++,j++){
        des->s[j] = src->s[i];
    }
    des->l = l;
    des->c = st+src->c; //des���� ���ڿ�ʼȡ����λ�ü���src����
}

void add(pNode pa,pNode pb,pNode ans){
    int cc,k,len,alen,blen;
    int ta,tb,i;
    pNode temp;
    //��֤a�Ĵ��ݴ�
    if((pa->c<pb->c)){
        temp = pa;
        pa = pb;
        pb = temp;
    }
    //����Ĵ���Ϊ�������е�С�Ĵ��� ����   2100    ������������� С�Ĵ���
    //                                   3260000
    ans->c = pb->c;
    cc = 0;//��λ��ʼ��Ϊ0
    k = pa->c-pb->c;//a�����Ҫ����0   00|00623
                  //                   00|12
    //�������ĳ���
    alen = pa->l+pa->c;
    blen = pb->l+pb->c;
    len = alen>blen?alen:blen;//���ĸ��ܳ���
    //��ʱ ��Ҫ����Ĳ��ֵĳ��ȾͿ����������  ������ݲ��ֲ��������
    len = len-ans->c;

    //������Ӽ���
    for(i=0;i<len;i++){
        //��a��ȡ��
        if(i<k)//kΪa�����Ҫ����ĸ���
            ta = 0;
        else
            ta = pa->s[i-k];//��i=kʱ��������� ��ʱȡ��a�е�0λ����
        //��b��ȡ��
        if(i<pb->l)
            tb = pb->s[i];
        else //������b�����еĳ��� ����Ҫ��b�Ҳಹ����
            tb = 0;
        if(i>=pa->l+k)//���a������ȡ�꣬a�Ҳಹ��  ���󣡵ȺŰ�
            ta = 0;

        //ͬλ���
        ans->s[i] = (ta+tb+cc)%10;//��¼��λ֮�͵ĸ�λ��
        cc = (ta+tb+cc)/10;//�ó�Ӧ�ý���λ
    }
    if(cc){
        ans -> s[i++] = cc;//������һλ�������� ���ܽ�λ ���λ
    }//���i++  ��Ϊi��ʵ�ʳ���С1 ����Ҫ��1
    ans->l = i;
}

void mul(pNode pa,pNode pb,pNode ans){
    Node ah,al,bh,bl;//�����Ļ� �����Լ������ڴ�ռ�
    int ma = pa->l>>1;//���ȳ���2
    int mb = pb->l>>1;
    pNode temp;
    int cc,w,i;//cc��λ  w���pa��pa��һλ��
    Node t1,t2,t3,t4,z;//�����˺�Ľ�� ����Ҫһ��z������ʱ��ŵڶ�����Ӻ�Ľ��

    //�ֽ�������ж�  a �� b����Ϊ1 ��ʱ ma mbΪ0
    //�ֽ���� ��ʼ���� ���˷�
    //������ֽ⵽����ǲ��������˲�����
    if(!ma||!mb){
        //pa ���ڵ���pb
        if(!ma){
            temp = pa;
            pa = pb;
            pb = temp;
        }
        ans->c = pa->c + pb->c;
        //���˷�
        w = pb->s[0];//��ʱpֻ��һλ
        cc = 0;
        for(i=0;i<pa->l;i++){
            ans->s[i] = (w*pa->s[i]+cc)%10;
            cc = (w*pa->s[i]+cc)/10;//�����λ
        }
        if(cc) ans->s[i++] = cc;
        ans->l = i;
        return;
    }

    //�ֽ�
    cp(pa,&ah,ma,pa->l-ma);
    cp(pa,&al,0,ma);
    cp(pb,&bh,mb,pb->l-mb);
    cp(pb,&bl,0,mb);

    //�ֳ��ĸ��������
    mul(&ah,&bh,&t1);
    mul(&ah,&bl,&t2);
    mul(&al,&bh,&t3);
    mul(&al,&bl,&t4);

    //���
    add(&t3,&t4,ans);
    add(&t2,ans,&z);
    add(&t1,&z,ans);
}

int main()
{
    Node ans,a,b;
    cout<<"���������a:"<<endl;
    cin>>sa;
    cout<<"���������b:"<<endl;
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
    cout<<"���Ϊ:"<<endl;
    for(i=ans.l-1;i>=0;i--){
        cout<<ans.s[i];
    }
    cout<<endl;
    return 0;
}
