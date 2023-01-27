//洛谷p2758
//dp（3个比较）
#include<bits/stdc++.h>
using namespace std;
const int N=2005;
char str1[N],str2[N];
int dp[N][N];
int find(int a,int b,int c) { //返回最小的
	if(a<=b&&a<=c)return a;
	if(b<=a&&b<=c)return b;
	if(c<=a&&c<=b)return c;
};
//初始化边界
//从0个到i个相当于i次插入 
void init(int a,int b){
	for(int i=1;i<=a;i++)dp[i][0]=i;
	for(int i=1;i<=b;i++)dp[0][i]=i;
} 
int main() {
	cin>>str1>>str2;
	int s1=strlen(str1);
	int s2=strlen(str2);
	init(s1,s2);
	for(int i=1; i<=s1; i++) {
		for(int j=1; j<=s2; j++) {
			//注意数组下标
			if(str1[i-1]==str2[j-1])dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=find(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
				//分别对应删除，插入，更改 
		}
	};
	cout<<dp[s1][s2];
	return 0;
}
