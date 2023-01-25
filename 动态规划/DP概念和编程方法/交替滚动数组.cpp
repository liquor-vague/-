//只用两行背包，节省内存空间
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1005;
int dp[2][N],value[N],weight[N];
void solve(int n,int c);

int main() {
	int n,c;//n为物品数量，c为背包容量
	cin>>n>>c;
	for(int i=1; i<=n; i++)cin>>value[i];
	for(int i=1; i<=n; i++)cin>>weight[i];
	solve(n,c);
	return 0;
};
void solve(int n,int c) {
	int now=0,old=1;//now指向现在处理的，old指向上次处理的
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=c; j++) {
			int tmp=weight[i];
			if(j>=weight[i]) dp[now][j]=max(dp[old][j],dp[old][j-tmp]+value[i]);
			else dp[now][j]=dp[old][j];
		};
		swap(now,old);
	};
	cout<<dp[old][c];
}
