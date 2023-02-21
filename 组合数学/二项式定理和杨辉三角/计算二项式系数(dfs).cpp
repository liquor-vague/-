//洛谷1313 
#include<bits/stdc++.h>
using namespace std;
#define mod 10007
const int N=1005;
int c[N][N];
int fastpow(int a,int n){
	int ans=1;
	a=a%mod;
	while(n){
		if(n&1)ans=(ans*a)%mod;
		a=(a*a)%mod;
		n>>=1; 
	};
	return ans;
};
int dfs(int k,int n){
	if(!k)return c[n][k]=1;
	if(k==1)return c[n][k]=n;
	if(c[n][k])return c[n][k];//记忆化
	if(n-k<k)k=n-k;//算小不算大
	return c[n][k]=(dfs(k,n-1)+dfs(k-1,n-1))%mod; 
};
int main(){
	int a,b,k,n,m;
	cin>>a>>b>>k>>n>>m;
	c[1][0]=1,c[1][1]=1;
	int ans=1;
	a%=mod,b%=mod;//防止爆int 
	ans*=(fastpow(a,n)*fastpow(b,m))%mod;
	ans*=dfs(n,k)%mod;
	ans%=mod;
	cout<<ans;
	return 0;
} 
