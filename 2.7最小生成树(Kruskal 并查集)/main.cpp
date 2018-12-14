#include <iostream>
#include <algorithm>
/*
���鼯(���� ��¼���Ϻ�)  ���׷���������(�ݹ�) �ϲ�

���ݽṹ:
    ���� -> �洢���Ϻ�
    ������
*/

using namespace std;

const int N = 100;
int father[N];
int n,m;

//��
struct Edge{
    int u;
    int v;
    int w;
}e[N*N];

//�������
bool comb(Edge e1,Edge e2){
    return e1.w<e2.w;//��С��������
}

//��ʼ��father
void init(int n){
    for(int i=1;i<=n;i++){
        father[i] = i;
    }
}

//�������ڽ��  !�ݹ�
int Find(int x){
    if(x!=father[x])
        father[x] = Find(father[x]);//�ڵ��������ڵ�ͬʱ���ع��ʱ��Ҳ��ͬһ�����µĶ��㶼�ĳ����ڵļ��Ϻ�
    return father[x];
}

//�ϲ�  !��������� �гɹ���ʧ�� ����Ҫ����ֵ���ж��Ƿ�ɹ�
int Merge(int a,int b){// a b Ϊһ���ߵ������˵�
    int p = Find(a);
    int q = Find(b);
    if(p==q) return 0;// Ҳ����˵ ���л�·ʱ �Ͳ��ܺϲ�
    if(p>q)
        father[p] = q;// ���鼯 Լ�� С�ļ��ϺŸ�ֵ����ļ��Ϻ�
    else
        father[q] = p;
    return 1;
}

int Kruskal(int n){
    int ans = 0;
    for(int i=0;i<m;i++){
        if(Merge(e[i].u,e[i].v)){
            ans += e[i].w;
            n--;
            if(n==1){
                return ans;
            }
        }
    }
    return 0;
}

int main()
{
    cout<<"��������n�ͱ���m:"<<endl;
    cin>>n>>m;
    init(n);
    cout<<"��������u,v�ͱ�ֵw:"<<endl;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    sort(e,e+m,comb);
    int ans = Kruskal(n);
    cout<<ans<<endl;
    return 0;
}
