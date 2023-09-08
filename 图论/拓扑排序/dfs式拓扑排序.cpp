//luogu P1113
//dfs式拓扑排序 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+5;
int t[N],f[N];			//时间和答案
vector<int>edge[N];

int dfs(int x) {
	if(f[x])return f[x];	//已经被访问过
	for(int i=0; i<edge[x].size(); i++) {	//循环：x的每条出边指向的点
		f[x] = max(f[x],dfs(edge[x][i]));	//dp，求pre最大值
	};
	f[x]+=t[x];
	return f[x];
}

int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		int x,y;
		cin>>x>>t[i];
		cin>>y;
		while(y) {
			edge[y].push_back(x);		//y->x
			cin>>y;
		}
	};
	int ans = 0;
	for(int i=1; i<=n; i++)ans = max(ans,dfs(i));
	cout<<ans;
	return 0;
}
