#include <iostream>

using namespace std;
/*
�Ż���
    �Ҳ�������ҵ���pivotС���� ������Ҳ��ҵ���pivot����� ���߽��� ���ֱ����������һ�� ��ʱ���r[i]<pivot ��i��low���� ���r[i]>pivot ��i-1��pivot����

�����ܽ᣺
    ע������Խ�����⣨if������ �����r[n-1] �ж����Ҫ���� ��Ҫ�������ںţ�

*/

int Partition(int r[],int low,int high){
    int pivot = r[low];
    int i = low,j = high;
    while(i<j){
        //������ ������
        while(i<j&&r[j]>pivot) j--;
        while(i<j&&r[i]<=pivot) i++;//������<= ��Ϊr[i] i=low ʱ r[i]����pivot ��Ҫ�������ж�һλ
        if(i<j) swap(r[i++],r[j--]);
    }


    /*����ԭ���ж������ ���˵���
    if(r[i]<=pivot){
        swap(r[i],r[low]);
        return i;
    }else{
        swap(r[i-1],r[low]);  // ������ ������Խ�� ��i=0ʱ Ҳ���ǲ�����r[i]==pivot
        return i-1;
    }
    */



    if(r[i]>pivot){
        swap(r[i-1],r[low]);
        return i-1;
    }
    swap(r[i],r[low]);
    return i;


}

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
