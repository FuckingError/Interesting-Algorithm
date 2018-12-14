#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct Meet{
    int beg;
    int fin;
    int num;
}meet[1000]; //相当于这边已经初始化过一个 类型为Meet 名为meet的数组变量

class setMeet{
  public:
    void init();
    void solve();
  private:
    int n,ans;//n:会议总数 ans: 最大的安排会议总数
};

void setMeet::init(){
    cout<<"输入会议总数："<<endl;
    cin>>n;
    cout<<"输入开始时间和结束时间，以空格分开："<<endl;
    for(int i=0;i<n;i++){
        cin>>meet[i].beg>>meet[i].fin;
        meet[i].num = i+1;
    }
}

//排序规则
bool cmp(Meet x,Meet y){
    if(x.fin == y.fin)
        return x.beg > y.beg; //优先持续时间短的会议
    return x.fin < y.fin;
}

void setMeet::solve(){
    sort(meet,meet+n,cmp); //0 0+n
    cout<<"排序结束后会议如下："<<endl;
    cout<<"会议编号  "<<"开始时间  "<<"结束时间 "<<endl;
    for(int i = 0;i<n;i++){
        cout<<meet[i].num<<"\t"<<meet[i].beg<<"\t"<<meet[i].fin<<endl;
    }
    cout<<"选择参加的会议:"<<endl;
    ans = 1;
    int last = meet[0].fin;//记录下上一次被选择的会议的结束时间
    cout<<meet[0].num<<endl;
    for(int i = 1;i<n;i++){
        if(meet[i].beg>=last){
            cout<<meet[i].num<<endl;
            ans++;
            last = meet[i].fin;
        }
    }
    cout<<"最多可以安排的会议数量为"<<ans<<endl;
}

//读入数据
int main()
{
    setMeet sm;
    sm.init();
    sm.solve();
    return 0;

}
