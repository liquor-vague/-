//邻接表存树
//luogu2015
#include<bits/stdc++.h>
using namespace std;
const int N = 200;
struct node {
	int v,w;								//v是子节点，w是边[u,v]的值
	node(int v=0,int w=0):v(v),w(w) {};
};
vector<node>edge[N];
int dp[N][N],sum[N];						//sum[i]记录以i为根的子树的总边数
int n,q;
void dfs(int u,int father) {
	for(int i=0; i<edge[u].size(); i++) {	 //用i遍历u的所有子节点
		int v =edge[u][i].v , w = edge[u][i].w;
		if(v==father)continue;				//不回头搜索父亲
		dfs(v,u);							//递归到最深的叶子节点，然后返回
		sum[u] += sum[v]+1;					//子树上的总边数
		for(int j=min(q,sum[u]); j>=0; j--) {
			for(int k=0; k<=min(sum[v],j-1); k++)
				dp[u][j] = max(dp[u][j],dp[u][j-k-1]+dp[v][k]+w);

		}
	}
}

int main() {
	scanf("%d%d",&n,&q);					//n个点，留q个树枝
	for(int i=1; i<n; i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edge[u].push_back(node(v,w));		//把边[u,v]存到u的邻接表中
		edge[v].push_back(node(u,w));		//无向边
	};
	dfs(1,0);
	printf("%d",dp[1][q]);
	return 0;
}
