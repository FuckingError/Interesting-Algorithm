#include <iostream>
#include <algorithm>
using namespace std;
/*
2018��10��10�� 09:24:39
*/
const int M = 10000;
int x,n,i;
int s[M];
int a = 0;

int BinarySearch(int n,int s[],int x){//���Բ�ָ�������С ��Ϊ����������ָ��
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
    cout<<"Ԫ�ظ���:"<<endl;
    cin>>n;
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
    i = BinarySearch(n,s,x);
    if(i==-1){
        cout<<"û���ҵ�"<<endl;
    }else
        cout<<"Ҫ���ҵ�Ԫ���ڵ�"<<i+1<<"λ"<<endl;
    cout<<a;
    return 0;
}
