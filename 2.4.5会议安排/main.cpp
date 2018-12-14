#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct Meet{
    int beg;
    int fin;
    int num;
}meet[1000]; //�൱������Ѿ���ʼ����һ�� ����ΪMeet ��Ϊmeet���������

class setMeet{
  public:
    void init();
    void solve();
  private:
    int n,ans;//n:�������� ans: ���İ��Ż�������
};

void setMeet::init(){
    cout<<"�������������"<<endl;
    cin>>n;
    cout<<"���뿪ʼʱ��ͽ���ʱ�䣬�Կո�ֿ���"<<endl;
    for(int i=0;i<n;i++){
        cin>>meet[i].beg>>meet[i].fin;
        meet[i].num = i+1;
    }
}

//�������
bool cmp(Meet x,Meet y){
    if(x.fin == y.fin)
        return x.beg > y.beg; //���ȳ���ʱ��̵Ļ���
    return x.fin < y.fin;
}

void setMeet::solve(){
    sort(meet,meet+n,cmp); //0 0+n
    cout<<"���������������£�"<<endl;
    cout<<"������  "<<"��ʼʱ��  "<<"����ʱ�� "<<endl;
    for(int i = 0;i<n;i++){
        cout<<meet[i].num<<"\t"<<meet[i].beg<<"\t"<<meet[i].fin<<endl;
    }
    cout<<"ѡ��μӵĻ���:"<<endl;
    ans = 1;
    int last = meet[0].fin;//��¼����һ�α�ѡ��Ļ���Ľ���ʱ��
    cout<<meet[0].num<<endl;
    for(int i = 1;i<n;i++){
        if(meet[i].beg>=last){
            cout<<meet[i].num<<endl;
            ans++;
            last = meet[i].fin;
        }
    }
    cout<<"�����԰��ŵĻ�������Ϊ"<<ans<<endl;
}

//��������
int main()
{
    setMeet sm;
    sm.init();
    sm.solve();
    return 0;

}
