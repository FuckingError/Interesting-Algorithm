#include <iostream>

using namespace std;
const int INF =0x3fffffff;
const int N = 100;
bool flag[N];//�ж��Ƿ��Ѿ�������С������

int closest[N];
int lowcost[N];//�洢�ڵ�ǰ��С�������� �� �õ�������Ǹ���

void Prime(int n,int u0,int c[N][N]){ //�������n  ��ʼ����u0 ��Ȩ�ڽӾ��� C[n][n]
    flag[u0] = true;
    int i,j = 0;
    //��sʼ������
    for(i=1;i<=n;i++){
        if(i!=u0){
            closest[i] = u0;
            lowcost[i] = c[u0][i];
            flag[i] = false;
        }else{
            lowcost[i] = 0;
            flag[i] = true;
        }
    }

    //ѡ����Сֵ ������С������ ���¾���
    for(i=1;i<=n;i++){//��n-1������� ��Ϊ��֪��u0���ĸ����Ի���ѭ��n��
        int temp = INF;
        int t = u0;
        for(j=1;j<=n;j++){
            if((!flag[j])&&(lowcost[j]<temp)){
                t = j;
                temp = lowcost[j];
            }
        }
        // ��Ҫ�����Ҳ��������
        if(t==u0) break;//�Ѿ�ȫ����������С������ flagȫΪtrue

        //���ҳ�����Сֵ ������С������
        flag[t] = true;
        //����  �����ڽӾ��� j��
        for(j=1;j<=n;j++){
            if((!flag[j])&&(c[t][j]<lowcost[j])){
                lowcost[j] = c[t][j];
                closest[j] = t;
            }
        }
    }
}


int main()
{
    int n,c[N][N],m,u,v,w;
    int u0;
    cout<<"��������n�ͱ���m:"<<endl;
    cin>>n>>m;
    int sumcost = 0;
    //��ʼ��
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            c[i][j] = INF;
        }
    }
    cout<<"�������� u,v�ͱ�ֵw��"<<endl;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        c[u][v] = c[v][u] = w;
    }
    cout<<"����������"<<endl;
    cin >> u0;
    Prime(n,u0,c);
    cout<<"����lowcost������Ϊ��";
    for(int i=1;i<=n;i++){
        cout<<lowcost[i]<<" ";
        sumcost += lowcost[i];
    }
    cout<<endl;
    cout<<"������СֵΪ��"<<sumcost<<endl;
    return 0;
}
