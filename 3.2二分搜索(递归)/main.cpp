#include <iostream>
#include <algorithm>
/*
�ݹ�һ��Ҫ��סд �ݹ��������

*/
using namespace std;
const int M = 10000;
int n,x,i;
int s[M];

int BinarySearch(int s[],int x,int low,int high){
    //�ݹ����������
    if(low>high){
        return -1;
    }

    int middle = (low+high)/2;

    if(s[middle]==x){
        return middle;
    }else if(x<s[middle]){
        return BinarySearch(s,x,low,middle-1);
    }else{
        return BinarySearch(s,x,middle+1,high);//�������Ҫ��1
    }
}

int main()
{
    int low = 0,high;
    cout<<"Ԫ�ظ���:"<<endl;
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
    cout<<"����Ҫ���ҵ�Ԫ��"<<endl;
    cin>>x;
    i = BinarySearch(s,x,low,high);
    if(i==-1){
        cout<<"û���ҵ�"<<endl;
    }else
        cout<<"Ҫ���ҵ�Ԫ���ڵ�"<<i+1<<"λ"<<endl;
    return 0;
}
