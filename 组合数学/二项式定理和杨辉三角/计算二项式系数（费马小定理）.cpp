//洛谷1313 
//运用了费马小定理，要计算逆元
#include<bits/stdc++.h>
using namespace std;
#define mod 10007
const int N=10001;
int fac[N];//阶乘 
int inv[N];//逆 
int fastpow(int a,int n){
	a%=mod;
	int ans=1;
	while(n){
		if(n&1)ans=(ans*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return ans;
};
int C(int n,int m){//计算组合数 
	return(fac[n]*inv[m]%mod*inv[n-m]%mod)%mod;
}
int main(){
	int a,b,k,n,m;
	cin>>a>>b>>k>>n>>m;
	fac[0]=1;
	for(int i=1;i<=k;i++){
		fac[i]=(fac[i-1])*i%mod;//计算阶乘 
		inv[i]=fastpow(fac[i],mod-2);//费马小定理求逆元 
	};
	int ans=(fastpow(a,n)%mod*fastpow(b,m)%mod*C(k,n)%mod)%mod;
	cout<<ans;
	return 0;
} 
