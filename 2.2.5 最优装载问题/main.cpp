#include <iostream>
#include <algorithm>
/*
2018��9��17�� 11:45:44
����װ�ص���������Ƕ���
�㷨���ԣ�̰���㷨
��̼��ɣ�c++�������������
          ʹ��sort����
          �������洢��������Ԫ�صĵ�ַ
*/
const int N = 10005;
using namespace std;
double w[N]; //�Ŷ�������
int main()
{
   double c;
   int n;
   cout<<"������������c���Ŷ�����n:"<<endl;
   cin>>c>>n;
   cout<<"������ÿ���Ŷ����������ÿո������"<<endl;
   for(int i=0;i<n;i++){
       cin>>w[i];
   }
   sort(w,w+n); //! ����������˵����������¼���׸�����Ԫ�صĵ�ַ
   double temp =0.0; //�Ѿ�װ�ص����ϵ�����
   int ans = 0;//�Ѿ�װ�صĹŶ�����
   for(;ans<c;ans++){
       temp += w[ans];
       if(temp>c)
         break;
   }
   cout<<"������ĹŶ��������Ϊ:"<<ans<<endl;
   return 0;
}
