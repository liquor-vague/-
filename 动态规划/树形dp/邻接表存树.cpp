//�ڽӱ����
//luogu2015
#include<bits/stdc++.h>
using namespace std;
const int N = 200;
struct node {
	int v,w;								//v���ӽڵ㣬w�Ǳ�[u,v]��ֵ
	node(int v=0,int w=0):v(v),w(w) {};
};
vector<node>edge[N];
int dp[N][N],sum[N];						//sum[i]��¼��iΪ�����������ܱ���
int n,q;
void dfs(int u,int father) {
	for(int i=0; i<edge[u].size(); i++) {	 //��i����u�������ӽڵ�
		int v =edge[u][i].v , w = edge[u][i].w;
		if(v==father)continue;				//����ͷ��������
		dfs(v,u);							//�ݹ鵽�����Ҷ�ӽڵ㣬Ȼ�󷵻�
		sum[u] += sum[v]+1;					//�����ϵ��ܱ���
		for(int j=min(q,sum[u]); j>=0; j--) {
			for(int k=0; k<=min(sum[v],j-1); k++)
				dp[u][j] = max(dp[u][j],dp[u][j-k-1]+dp[v][k]+w);

		}
	}
}

int main() {
	scanf("%d%d",&n,&q);					//n���㣬��q����֦
	for(int i=1; i<n; i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edge[u].push_back(node(v,w));		//�ѱ�[u,v]�浽u���ڽӱ���
		edge[v].push_back(node(u,w));		//�����
	};
	dfs(1,0);
	printf("%d",dp[1][q]);
	return 0;
}
