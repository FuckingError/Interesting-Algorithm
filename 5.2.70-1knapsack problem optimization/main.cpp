#include <iostream>
#include <cstring>
#include <algorithm>

#define M 105
using namespace std;
/*
2018��12��14�� 21:40:15
��Ҫ���Ż������ڣ��Ż��޽纯������Ϊԭ���޽纯���ǽ�ʣ����ļ�ֵͳͳ���ϣ����ǿ��ܻ������Ȼ�ܼ�ֵ�������м�ֵ�����Ǵ�ʱ��������������
����������޽纯��Ҫ�Ա��������������ƣ��Ӷ����Ӽӿ�����

ע�⣺
 1.memset ��Ӧ��ͷ�ļ��� cstring
 2.sort   ��Ӧ��ͷ�ļ��� algorithm

*/
int i,j,n,W;//n����Ʒ���� W�ǹ��ﳵ����
double w[M],v[M];//��Ʒ���� ��Ʒ��ֵ
bool x[M];//��¼��ÿһ���������ѡ��
double cw = 0.0,cp = 0.0;//��ǰ���� ��ǰ��ֵ

double bestp;//����ֵ
bool bestx[M];//�洢����ѡ��


//�ṹ�� ���ڶԵ�λ��������Ʒ��ֵ�������� �����Ż��޽纯��
struct Object{
    int id;//���
    double w;
    double v;
    //double d;//��λ�����ļ�ֵ ��������ıȽ϶���
};

bool cmp(Object o1,Object o2){// ! ������Ʒ��λ������ֵ�ɴ�С����
    return o1.v/o1.w>o2.v/o2.w;
}

double Bound(int i){//�����Ͻ� !����������Ż��ĵط���  �����ʣ����Ʒװ��ʣ�౳����������õ�����ֵ
    double left = W-cw;//ʣ������
    double brp = 0.0;//ʣ������������ֵ
    // ! ��Ҫ����һѭ�� ������forѭ��
    //��������ֵ
    //while(i<=n&&left>=0){  ��ע�������ʣ���������ж����� ��д����
    while(i<=n&&left>=w[i]){
        left -= w[i];
        brp += v[i];
        i++;
    }
    return brp;
}

void Backtrack(int t){//��t��
    if(t>n){//�Ѿ�����Ҷ�ӽ��
        for(i=1;i<=n;i++){
            bestx[i] = x[i];
        }
        bestp = cp;
        return;
    }

    //���� ��Ӧ����Լ������
    if(cw+w[t]<=W){
        //��չ����
        cw += w[t];
        cp += v[t];
        x[t] = 1;
        //�������±���
        Backtrack(t+1);
        //����һ��Ҫ��ȥ���ϵ�w �� v ����������ҽ�����
        cw -= w[t];
        cp -= v[t];
    }

    //��չ�ҽ�� �޽纯��
    if(Bound(t+1)+cp>bestp){ // �� �ж��������ܻ��ж���д�� ѡ��һ����ֱ�۵�д��
        x[t] = 0;
        Backtrack(t+1);
    }

}

void Knapsack(){
    //��ȫ�ֱ������г�ʼ��
    //cw = 0;
    cw = 0;
    cp = 0;
    bestp = 0; // !Ҫ��ʼ��ȫ�ֱ�����
    double sumW=0.0,sumV=0.0;
    Object Q[n];
    memset(Q,0,sizeof(Object)*n);

    //��Ʒȫ���������� �ж��Ƿ��������
    //ͬʱ ��v w���뵽�ṹ��������
    for(i=1;i<=n;i++){
        sumW += w[i];
        sumV += v[i];
        //���뵽�ṹ����
        Q[i-1].id = i;
        Q[i-1].v = v[i];
        Q[i-1].w = w[i];
        //Q[i].d = v[i]/w[i];
    }

    if(sumV<=W){
        cout<<"ȫ��������װ��"<<endl;
        cout<<"���빺�ﳵ������ֵΪ"<<sumV<<endl;
        return;
    }

    //����
    sort(Q,Q+n,cmp);


    //�������뵽W �� V������
    for(i=1;i<=n;i++){
        w[i] = Q[i-1].w;
        v[i] = Q[i-1].v;
    }
    //����Backtrack
    Backtrack(1);
    cout<<"����ֵΪ:"<<bestp<<endl;
    cout<<"�������Ʒ���Ϊ��";
    for(i=1;i<=n;i++){
        if(bestx[i]==1)
            cout<<Q[i-1].id<<" ";
    }
    cout<<endl;
}

int main()
{
    cout<<"��Ʒ�����͹��ﳵ������"<<endl;
    cin>>n>>W;
    cout<<"������Ʒ�����ͼ�ֵ"<<endl;
    for(i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    Knapsack();
    return 0;
}
