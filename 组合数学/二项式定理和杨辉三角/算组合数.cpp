#include<iostream>
using namespace std;
#define mod 1007
const int N=1005;
int c[N][N];
int dfs(int k,int n){
	if(!k)return c[n][k]=1;
	if(k==1)return c[n][k]=n;
	if(c[n][k])return c[n][k];//记忆化
	if(n-k<k)k=n-k;//算小不算大
	return c[n][k]=(dfs(k-1,n-1)+dfs(k,n-1))%mod; 
};
int main(){
	c[1][0]=1,c[1][1]=1;
	cout<<dfs(4,5);
	return 0;
} 
