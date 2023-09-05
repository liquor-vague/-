//hdu5418
//TSP问题（可走重复节点）
//状压DP 

#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int G[20][20];
int dp[1<<16][20];
//dp的第一维表示去过的状态，第二维表示当前所在节点，因为每个点可以去无数次

void solve() {
	int n,m;
	cin>>n>>m;
	memset(G,inf,sizeof(G));
	memset(dp,inf,sizeof(dp));

	while(m--) {				//输入路径
		int u,v,w;
		cin>>u>>v>>w;
		G[u][v] = min(G[u][v],w);
		G[v][u] = min(G[v][u],w);
	};

	for(int i=1; i<=n; i++) {	//优化
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) {
				if(i==j)G[i][j] = 0;		//到原点距离为0 
				else G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	};
	dp[2][1] = 0;						//由于编号从1开始，最低位用不上 

	for(int i=1; i<=(1<<(n+1)); i++) {
		for(int j = 1; j<=n; j++) {
			if(!(i&(1<<j)))continue;	//如果没经过这个节点，跳过
			for(int k = 1; k<=n; k++) {
				dp[i|(1<<k)][k] = min(dp[i|(1<<k)][k],dp[i][j]+G[j][k]);
			}
		}
	}

	cout<<dp[((1<<(n+1))-2)][1]<<'\n';		//因为第一位用不上所以-2，注意位运算的优先级 

}

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
