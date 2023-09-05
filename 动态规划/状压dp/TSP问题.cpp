//hdu5418
//TSP���⣨�����ظ��ڵ㣩
//״ѹDP 

#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int G[20][20];
int dp[1<<16][20];
//dp�ĵ�һά��ʾȥ����״̬���ڶ�ά��ʾ��ǰ���ڽڵ㣬��Ϊÿ�������ȥ������

void solve() {
	int n,m;
	cin>>n>>m;
	memset(G,inf,sizeof(G));
	memset(dp,inf,sizeof(dp));

	while(m--) {				//����·��
		int u,v,w;
		cin>>u>>v>>w;
		G[u][v] = min(G[u][v],w);
		G[v][u] = min(G[v][u],w);
	};

	for(int i=1; i<=n; i++) {	//�Ż�
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) {
				if(i==j)G[i][j] = 0;		//��ԭ�����Ϊ0 
				else G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	};
	dp[2][1] = 0;						//���ڱ�Ŵ�1��ʼ�����λ�ò��� 

	for(int i=1; i<=(1<<(n+1)); i++) {
		for(int j = 1; j<=n; j++) {
			if(!(i&(1<<j)))continue;	//���û��������ڵ㣬����
			for(int k = 1; k<=n; k++) {
				dp[i|(1<<k)][k] = min(dp[i|(1<<k)][k],dp[i][j]+G[j][k]);
			}
		}
	}

	cout<<dp[((1<<(n+1))-2)][1]<<'\n';		//��Ϊ��һλ�ò�������-2��ע��λ��������ȼ� 

}

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
