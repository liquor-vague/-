//luogu p1113
//bfs式拓扑排序 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
int ind[N],f[N],t[N];	//入度，答案，时间
vector<int>edge[N];
queue<int>q; 

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>t[i];
		while(cin>>y){
			if(!y)break;
			edge[y].push_back(x);	//x插入到y后
			ind[x]++;				//x入度+1 
		}
	};
	//找到入度为0的点，入队 
	for(int i=1;i<=n;i++){
		if(ind[i] == 0){
			q.push(i);
			f[i] = t[i];
		}
	}
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		//检查每一段 
		for(int i=0;i<edge[cur].size();i++){
			int tmp = edge[cur][i];
			ind[tmp]--;
			if(ind[tmp]==0)q.push(tmp);
			f[tmp] = max(f[tmp],f[cur]+t[tmp]);	//贪心，可能不止一次走过这里 
		}
	};
	
	int ans = 0;
	for(int i=1;i<=n;i++)ans = max(ans,f[i]);
	cout<<ans;
	
	return 0;
} 
