#include <iostream>
/*
2018年10月19日 10:45:32

动态规划中 构造最优解往往是通过递归实现的  或者直接由二维数组得出
*/
using namespace std;
const int ms = 1000;
int r[ms][ms],m[ms][ms],s[ms][ms];//各站点租金  租金记录  路线记录
int n;//一共有n个站点

void rent(){
    int i,j,k,d;

    //将问题 分小规模
    for(d=3;d<=n;d++){//问题规模为3  依次增加
        for(i=1;i<=n-d+1;i++){ //出发点 i
            j = i+d-1;//终点
            for(k=i+1;k<j;k++){//中间停靠的k
                int temp = m[i][k]+m[k][j];//计算出开销 这里相当于调用之前更小规模的记录  就不需要重复计算了  体现动态规划
                if(temp<m[i][j]){
                    m[i][j] = temp;
                    s[i][j] = k;
                }
            }
        }
    }
}

//递归
void print(int i,int j){
    int k = s[i][j];
    if(k!=0){
        print(i,k);
        cout<<k<<endl;
        print(k,j);
    }
}

int main()
{
   int i,j;
   cout<<"请输入站点的个数:"<<endl;
   cin>>n;
   cout<<"请输入站点之间的租金:"<<endl;
   for(i=1;i<=n;i++){
    for(j=i+1;j<=n;j++){
        cin>>r[i][j];
        m[i][j] = r[i][j];
    }
   }
   rent();
   cout<<"最少租金为:"<<m[1][n]<<endl;
   print(1,n);
   return 0;
}
