#include <iostream>
/*
2018��10��12�� 18:57:19
swap() ��������
����:
    ����˼��(��ϵݹ�)
    ����һ����׼ֵ������Ϊ��׼��������С�ķ���ߣ���ķ��ұ�
        �ȴ�������ɨ�� ֱ���ҵ�һ������С��ֵ ��pivot����λ��
        �ٴ�������ɨ�� ֱ���ҵ�һ���������ֵ ��pivot����λ��
    ֱ����������һ��  ��һ�ο��Ž���

    ��ʱ����pivotΪ���ģ���඼�Ǳ�pivotС�� �Ҳ඼�Ǳ�pivot��ģ���� �� �Ҳ� ������ �ֱ��ٽ��п��� ֱ���ֳ�һ����


*/
using namespace std;

//���ֺ���
int Partition(int r[],int low,int high){
    int pivot = r[low];//�Ե�һ����Ϊ��׼
    int i = low,j = high;
    while(i<j){//��i = j �����һ�ο��Ž���
        //��whileѭ���� �ֳ������ֵ�ѭ�� ���� ����
        //����  ��pivotС����pivot����
        while(i<j&&r[j]>pivot) j--;
        //����whileѭ�� �����ֿ��� һ���ǲ�����i<j  һ�����ҵ���С��pivot��ֵ
        if(i<j){
            swap(r[i++],r[j]); //�������� i����ƶ�һλ
        }
        while(i<j&&r[i]<pivot) i++;
        if(i<j){
            swap(r[i],r[j--]); //j��ǰ�ƶ�һλ
        }
    }
    return i;//���ؿ��Ž�������е�
}

//��������
void QuickSort(int r[],int low,int high){
    if(low<high){
        int mid = Partition(r,low,high);
        QuickSort(r,low,mid-1);
        QuickSort(r,mid+1,high);
    }
}


int main()
{
    int a[1000];
    int i,N;
    cout<<"������������ݵĸ���"<<endl;
    cin>>N;
    //cout<<endl;
    cout<<"��������:"<<endl;
    for(i=0;i<N;i++){
        cin>>a[i];
    }
    cout<<endl;
    QuickSort(a,0,N-1);
    cout<<"����������Ϊ:"<<endl;
    for(i=0;i<N;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
