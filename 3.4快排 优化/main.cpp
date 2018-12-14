#include <iostream>

using namespace std;
/*
优化：
    右侧往左侧找到比pivot小的数 左侧往右侧找到比pivot大的数 两者交换 最后直到左右碰到一块 此时如果r[i]<pivot 则将i与low交换 如果r[i]>pivot 则将i-1与pivot交换

错误总结：
    注意数组越界问题（if括号内 如果有r[n-1] 判断语句要当心 不要包含等于号）

*/

int Partition(int r[],int low,int high){
    int pivot = r[low];
    int i = low,j = high;
    while(i<j){
        //先向左 再向右
        while(i<j&&r[j]>pivot) j--;
        while(i<j&&r[i]<=pivot) i++;//这里是<= 因为r[i] i=low 时 r[i]就是pivot 需要往后再判断一位
        if(i<j) swap(r[i++],r[j--]);
    }


    /*错误原因：判断语句中 少了等于
    if(r[i]<=pivot){
        swap(r[i],r[low]);
        return i;
    }else{
        swap(r[i-1],r[low]);  // ！错误处 当数组越界 当i=0时 也就是不能让r[i]==pivot
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
    cout<<"输入排序的数据的个数"<<endl;
    cin>>N;
    //cout<<endl;
    cout<<"输入数据:"<<endl;
    for(i=0;i<N;i++){
        cin>>a[i];
    }
    cout<<endl;
    QuickSort(a,0,N-1);
    cout<<"排序后的序列为:"<<endl;
    for(i=0;i<N;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
