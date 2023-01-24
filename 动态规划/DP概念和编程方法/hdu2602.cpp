//hdu2602
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1005;
int dp[N][N],value[N],volume[N];
int n,c;//骨头数量和背包容量
void search();
int main() {
	int t;
	cin>>t>>n>>c;
	while(t--) {
		for(int i=1; i<=n; i++)cin>>value[i];
		for(int i=1; i<=n; i++)cin>>volume[i];
		search();
		cout<<dp[n][c];
	}

for(int i=1;i<=n;i++){
	for(int j=1;j<=c;j++)cout<<dp[i][j]<<"\t" ;
	cout<<endl;
}

	return 0;
};
void search() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=c; j++) {
			
			if(j>=volume[i]) {
				int tmp=volume[i];
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-tmp]+value[i]);
			} 
			else {
				dp[i][j]=dp[i-1][j];
			}


		}
	}
}
