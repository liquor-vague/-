//hdu 1712
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int dp[N];
int v[N][N],w[N][N];//v代表学分，w代表学时 
int main(){
	ios::sync_with_stdio(0);
	int n,m;//有n门课，学m天 
	while((cin>>n>>m)&&n&&m){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>v[i][j];
				w[i][j]=j;
			}
		};
		
		memset(dp,0,sizeof(dp));
		
		for(int i=1;i<=n;i++){//n门课 
			for(int j=m;j>0;j--){//容量为m 
				for(int k=1;k<=m;k++){//用k次遍历第i组 
					if(j>=w[i][k]){
						dp[j]=max(dp[j],dp[j-w[i][k]]+v[i][k]);
					}
				}
			}
		};
		
		printf("%d",dp[m]); 
	}
	return 0; 
}
