#include <iostream>
#include <algorithm>
using namespace std;
/*
2018年10月10日 09:24:39
*/
const int M = 10000;
int x,n,i;
int s[M];
int a = 0;

int BinarySearch(int n,int s[],int x){//可以不指定数组大小 因为数组名就是指针
    int low = 0,high = n-1;
    while(low <= high){
        a++;
        int middle = (low+high)/2;
        if(x == s[middle]){
            return middle;
        }else if(x<s[middle]){
            high = middle-1;
        }else
            low = middle+1;
    }
    return -1;
}

int main()
{
    cout<<"元素个数:"<<endl;
    cin>>n;
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
    i = BinarySearch(n,s,x);
    if(i==-1){
        cout<<"没有找到"<<endl;
    }else
        cout<<"要查找的元素在第"<<i+1<<"位"<<endl;
    cout<<a;
    return 0;
}
