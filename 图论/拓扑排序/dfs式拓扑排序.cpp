//luogu P1113
//dfsʽ�������� 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+5;
int t[N],f[N];			//ʱ��ʹ�
vector<int>edge[N];

int dfs(int x) {
	if(f[x])return f[x];	//�Ѿ������ʹ�
	for(int i=0; i<edge[x].size(); i++) {	//ѭ����x��ÿ������ָ��ĵ�
		f[x] = max(f[x],dfs(edge[x][i]));	//dp����pre���ֵ
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
