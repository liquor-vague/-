//luogu p1113
//bfsʽ�������� 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
int ind[N],f[N],t[N];	//��ȣ��𰸣�ʱ��
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
			edge[y].push_back(x);	//x���뵽y��
			ind[x]++;				//x���+1 
		}
	};
	//�ҵ����Ϊ0�ĵ㣬��� 
	for(int i=1;i<=n;i++){
		if(ind[i] == 0){
			q.push(i);
			f[i] = t[i];
		}
	}
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		//���ÿһ�� 
		for(int i=0;i<edge[cur].size();i++){
			int tmp = edge[cur][i];
			ind[tmp]--;
			if(ind[tmp]==0)q.push(tmp);
			f[tmp] = max(f[tmp],f[cur]+t[tmp]);	//̰�ģ����ܲ�ֹһ���߹����� 
		}
	};
	
	int ans = 0;
	for(int i=1;i<=n;i++)ans = max(ans,f[i]);
	cout<<ans;
	
	return 0;
} 
