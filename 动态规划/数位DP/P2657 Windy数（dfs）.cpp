#include<bits/stdc++.h>
using namespace std;
int dp[15][15],num[15];//dp[pos][last]��ʾ���ֳ���Ϊposλ��ǰһλ��last����� 
int dfs(int pos,int last,bool lead,bool limit){//lead��ʾ��ʶ0��limitΪ��λ���� 
	int ans=0;
	if(pos==0)return 1;
	if(!lead&&!limit&&dp[pos][last]!=-1)return dp[pos][last];
	int up=(limit?num[pos]:9);
	for(int i=0;i<=up;i++){
		if(abs(i-last)<2)continue;//����windy��
		if(lead&&i==0) ans+=dfs(pos-1,-2,1,limit&&i==up);
		else ans+=dfs(pos-1,i,0,limit&&i==up); 
	};
	if(!limit&&!lead)dp[pos][last]=ans;
	return ans;
};
int solve(int x){
	int len=0;
	while(x){
		num[++len]=x%10;
		x/=10;
	};
	memset(dp,-1,sizeof(dp));
	return dfs(len,-2,1,1);
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<solve(b)-solve(a-1);
	return 0;
} 
