#include<iostream>
#include<algorithm>
using namespace std;
const int N=1005;
int dp[N],value[N],weight[N];
void solve(int n,int c);

int main() {
	int n,c;//n为物品数量，c为背包容量
	cin>>n>>c;
	for(int i=1; i<=n; i++)cin>>value[i];
	for(int i=1; i<=n; i++)cin>>weight[i];
	solve(n,c);
	return 0;
};

void solve(int n, int c){
	for(int i=1; i<=n; i++) {
		for(int j=c; j>=weight[i]; j--) {//反过来循环 
			int tmp=weight[i];
			dp[j]=max(dp[j],dp[j-tmp]+value[i]);
		}
	};
	cout<<dp[c];
}
