#include <iostream>
#include <algorithm>
/*
2018年9月17日 11:45:44
求能装载的最大数量是多少
算法策略：贪心算法
编程技巧：c++基本的输入输出
          使用sort排序
          数组名存储了数组首元素的地址
*/
const int N = 10005;
using namespace std;
double w[N]; //古董的重量
int main()
{
   double c;
   int n;
   cout<<"请输入载重量c及古董个数n:"<<endl;
   cin>>c>>n;
   cout<<"请输入每个古董的重量，用空格隔开："<<endl;
   for(int i=0;i<n;i++){
       cin>>w[i];
   }
   sort(w,w+n); //! 对于数组来说，数组名记录了首个数组元素的地址
   double temp =0.0; //已经装载到穿上的重量
   int ans = 0;//已经装载的古董个数
   for(;ans<c;ans++){
       temp += w[ans];
       if(temp>c)
         break;
   }
   cout<<"能载入的古董最大数量为:"<<ans<<endl;
   return 0;
}
