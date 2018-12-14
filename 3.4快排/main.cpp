#include <iostream>
/*
2018年10月12日 18:57:19
swap() 交换函数
快排:
    分治思想(结合递归)
    先找一个标准值，以它为标准，将比它小的放左边，大的放右边
        先从左向右扫描 直到找到一个比它小的值 与pivot交换位置
        再从右向左扫描 直到找到一个比它大的值 与pivot交换位置
    直到左右碰到一块  第一次快排结束

    此时，以pivot为中心，左侧都是比pivot小的 右侧都是比pivot大的，左侧 和 右侧 两部分 分别再进行快排 直到分成一个数


*/
using namespace std;

//划分函数
int Partition(int r[],int low,int high){
    int pivot = r[low];//以第一个点为标准
    int i = low,j = high;
    while(i<j){//当i = j 代表第一次快排结束
        //该while循环中 分成两部分的循环 向左 向右
        //向左  比pivot小的与pivot交换
        while(i<j&&r[j]>pivot) j--;
        //跳出while循环 有两种可能 一种是不满足i<j  一种是找到了小于pivot的值
        if(i<j){
            swap(r[i++],r[j]); //交换过后 i向后移动一位
        }
        while(i<j&&r[i]<pivot) i++;
        if(i<j){
            swap(r[i],r[j--]); //j向前移动一位
        }
    }
    return i;//返回快排结束后的中点
}

//快速排序
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
