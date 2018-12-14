#include <iostream>

using namespace std;
/*
2018年10月10日 22:24:12
*/
void Merge(int A[],int low,int mid,int high){
    //申请数组空间 存放排完序的数组
    int *B = new int[high-low+1];
    int i = low,j = mid+1,k = 0;
    while(i<=mid&&j<=high){
        if(A[i]<A[j]){//从小到大排序
            B[k++] = A[i];
        }else
            B[k++] = A[j];
    }
    while(i<=mid) B[k++] = A[i++];// ! 技巧啊  数组之间赋值的技巧啊
    while(j<=high) B[k++] = B[j++];
    //重新B赋值给A
    for(i=0,k=0;i<=high;i++){
        A[i] = B[k++];
    }
    delete[] B;
}

//合并排序  递归
void MergeSort(int A[],int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);//合并
    }
}


int main()
{
    int n,A[100];
    cout<<"请输入数列中的元素个数:"<<endl;
    cin >> n;
    cout<<"请依次输入数列中的元素"<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    MergeSort(A,0,n-1);
    cout<<"排序结果:"<<endl;
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}
