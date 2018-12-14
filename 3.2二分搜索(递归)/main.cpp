#include <iostream>
#include <algorithm>
/*
递归一定要记住写 递归结束条件

*/
using namespace std;
const int M = 10000;
int n,x,i;
int s[M];

int BinarySearch(int s[],int x,int low,int high){
    //递归结束的条件
    if(low>high){
        return -1;
    }

    int middle = (low+high)/2;

    if(s[middle]==x){
        return middle;
    }else if(x<s[middle]){
        return BinarySearch(s,x,low,middle-1);
    }else{
        return BinarySearch(s,x,middle+1,high);//这里必须要加1
    }
}

int main()
{
    int low = 0,high;
    cout<<"元素个数:"<<endl;
    cin>>n;
    high = n-1;
    for(i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s,s+n);
    for(i=0;i<n;i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
    cout<<"输入要查找的元素"<<endl;
    cin>>x;
    i = BinarySearch(s,x,low,high);
    if(i==-1){
        cout<<"没有找到"<<endl;
    }else
        cout<<"要查找的元素在第"<<i+1<<"位"<<endl;
    return 0;
}
