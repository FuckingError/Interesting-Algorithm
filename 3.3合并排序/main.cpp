#include <iostream>

using namespace std;
/*
2018��10��10�� 22:24:12
*/
void Merge(int A[],int low,int mid,int high){
    //��������ռ� ��������������
    int *B = new int[high-low+1];
    int i = low,j = mid+1,k = 0;
    while(i<=mid&&j<=high){
        if(A[i]<A[j]){//��С��������
            B[k++] = A[i];
        }else
            B[k++] = A[j];
    }
    while(i<=mid) B[k++] = A[i++];// ! ���ɰ�  ����֮�丳ֵ�ļ��ɰ�
    while(j<=high) B[k++] = B[j++];
    //����B��ֵ��A
    for(i=0,k=0;i<=high;i++){
        A[i] = B[k++];
    }
    delete[] B;
}

//�ϲ�����  �ݹ�
void MergeSort(int A[],int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);//�ϲ�
    }
}


int main()
{
    int n,A[100];
    cout<<"�����������е�Ԫ�ظ���:"<<endl;
    cin >> n;
    cout<<"���������������е�Ԫ��"<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    MergeSort(A,0,n-1);
    cout<<"������:"<<endl;
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}
