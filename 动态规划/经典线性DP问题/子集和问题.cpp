/*用dp求解子集和问题。
当dp[i][j]=1时，表示S的前i个元素存在一个子集和等于j。
答案就是dp[i][M]
*/ 

#include<iostream>
using namespace std;
const int N=1005; 
int dp[N][N],s[N];
int main(){
	int t;//集合S中元素的个数
	cin>>t;
	for(int i=1;i<=t;i++)cin>>s[i];
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)dp[i][0]=1;//注意初始是纵轴的值为1 
	for(int i=1;i<=t;i++){
		for(int j=1;j<=m;j++){
			if(j<s[i])dp[i][j]=dp[i-1][j];
			else{
				dp[i][j]=(dp[i-1][j]||dp[i-1][j-s[i]]);
			}
		}
	};
	cout<<dp[t][m];
}
