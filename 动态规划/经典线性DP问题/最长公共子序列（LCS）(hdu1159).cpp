//hdu1159
//复杂度为O(n*m) 
#include<iostream>
#include<string.h>
using namespace std;
const int N=1005;
char str1[N],str2[N];
int dp[N][N];
int main(){
	cin>>str1>>str2;
	int s1=strlen(str1),s2=strlen(str2);
	for(int i=0;i<s1;i++){
		for(int j=0;j<s2;j++){
			if(str1[i]==str2[j])dp[i+1][j+1]=dp[i][j]+1;//防止数组越界
			else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]); 
		}
	};
	cout<<dp[s1][s2];
	return 0;
} 
