#include <iostream>
#define M 105
using namespace std;
/*
2018��12��14�� 19:10:04
ͨ������x[M]�����������һ����֧  ���� ����������

*/

int i,j,n,W;//n��ʾn����Ʒ W��ʾ���ﳵ������
double w[M],v[M];//w[i]��ʾ��i����Ʒ������ v[i]��ʾ��i����Ʒ�ļ�ֵ
bool x[M];//�Ƿ���빺�ﳵ
double cw;//��ǰ����
double cp;//��ǰ��ֵ
double bestp;//��ǰ���ż�ֵ
bool bestx[M];//��ǰ���Ž�

//����t�� ���ҽ�������չǰ������Ͻ�  ����Ҫ����t+1�Լ�֮����ļ�ֵ֮��
double Bound(int i){//��i�㿪ʼ����
    int rp = 0;
    while(i<=n){
        rp += v[i];
        i++;
    }
    return cp+rp;
}


// ! ������������е�if�ǳ����� Ҫ�ٺú��о�һ��
void Backtrack(int t){ //t��ʾ��ǰ��չ����ڵ�t��
    //�����ʱ�Ѿ��ﵽҶ�ӽ�� ������ܼ�ֵ �����и���
    //����Ҷ�ӽ���һ�����ǵ�ǰ�����Ž� ���Ը�����һ�����Ž�
    /*��Ϊ�� ��������ӵ�ǰ�����չ�ҽ�� ���ж��Ͻ�ֵ�Ƿ���ڵ�ǰ����ֵ ������ڲŻ���б���
             ��ʼ���������һֱ������ֱ�����������ʱ����ض������Ž�
             ���������������չ������Ҫ�ж��Ͻ�ֵ�Ƿ��������ֵ����������ڣ��������������չ��ֱ�����Ҳ�ض�������ֵ
                                                                 ���С�ڵĻ����Ͳ���������չ��.
             ����ÿ�β���һ���µĽ������һ�������Ž⣬����Ҳ�Ͳ���Ҫ�����ж���

    */
    if(t>n){
        for(j=1;j<=n;j++){
            bestx[j] = x[j];//���浱ǰ���Ž�  ����õ��Ľ��һ�������Ž�
        }
        bestp = cp;//���浱ǰ���Ž�
        return;
    }

    //��������Լ����cw<=W
    if(cw+w[t]<=W){
        x[t] = 1;//���빺�ﳵ
        cw += w[t];
        cp += v[t];
        Backtrack(t+1);
        //t-1���������������� ���ݵ���ǰt-1�� (��ȥt���ֵ)
        cw -= w[t];
        cp -= v[t];
    }
    //��ǰt-1���������������Ϻ� �ֻ��ݵ�t-1�� ׼��������չ������
    if(Bound(t+1)>bestp){//�����������������������������
        x[t] = 0;
        Backtrack(t+1);
    }
}

void Knapsack(double W,int n){
    //��ʼ��
    cw = 0;
    cp = 0;
    bestp = 0;
    double sumw = 0.0;//ͳ��������Ʒ������
    double sumv = 0.0;//ͳ��������Ʒ��ֵ

    //��������Ʒ���Ͽ����Ƿ�С�ڵ�ǰ����������ǣ��򶼷���
    for(i=1;i<=n;i++){
        sumv+=v[i];
        sumw+=w[i];
    }
    if(sumw<=W){
        bestp=sumv;
        cout<<"����ֵΪ:"<<bestp<<endl;
        cout<<"���е���Ʒ�����빺�ﳵ";
        return;
    }
    //���ǿ�ʼ����
    Backtrack(1);
    cout<<"���빺�ﳵ����Ʒ����ֵΪ:"<<bestp<<endl;
    cout<<"���빺�ﳵ����Ʒ���Ϊ:";
    for(i=1;i<=n;i++){
        if(bestx[i]==1)
            cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    cout<<"��������Ʒ�ĸ���n��"<<endl;
    cin>>n;
    cout<<"�����빺�ﳵ������W:"<<endl;;
    cin>>W;
    cout<<"����������ÿ����Ʒ������w�ͼ�ֵv���ÿո����"<<endl;;
    for(i=1;i<=n;i++){// !Ϊ�˷��� �����1��ʼ����
        cin>>w[i]>>v[i];
    }
    Knapsack(W,n);
    return 0;
}