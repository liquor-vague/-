//hdu 1712
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int dp[N];
int v[N][N],w[N][N];//v����ѧ�֣�w����ѧʱ 
int main(){
	ios::sync_with_stdio(0);
	int n,m;//��n�ſΣ�ѧm�� 
	while((cin>>n>>m)&&n&&m){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>v[i][j];
				w[i][j]=j;
			}
		};
		
		memset(dp,0,sizeof(dp));
		
		for(int i=1;i<=n;i++){//n�ſ� 
			for(int j=m;j>0;j--){//����Ϊm 
				for(int k=1;k<=m;k++){//��k�α�����i�� 
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
