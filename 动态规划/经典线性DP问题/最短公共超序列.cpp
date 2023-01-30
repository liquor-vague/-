#include<iostream>
#include<string.h>
using namespace std;
const int N=1005;
char str1[N],str2[N],ans[N];//ans用来存放公共超序列
int len1,len2,count;
int dp[N][N];
int main(){
	int i,j;
	
	cin>>str1>>str2;
	len1=strlen(str1),len2=strlen(str2);
	
	//数组后移一位， 方便后续操作
	for(i=len1;i>0;i--)str1[i]=str1[i-1]; 
	for(i=len2;i>0;i--)str2[i]=str2[i-1];
	
	//给横纵坐标赋初值
	for(i=0;i<=max(len1,len2);i++)dp[i][0]=dp[0][i]=i;
	
	//计算公共超序列的位数
	for(i=1;i<=len1;i++){
		for(j=1;j<=len2;j++){
			//若字母已经在公共超序列中 
			if(str1[i]==str2[j])dp[i][j]=dp[i-1][j-1]+1;
			////若字母不在公共超序列中 
			else dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
		}
	};
	
	i=len1,j=len2;
	count=0;
	
	//计算公共超序列
	while(i>0&&j>0){
		//若相同 
		if(dp[i][j]==dp[i-1][j-1]+1&&str1[i]==str2[j]){
			ans[count]=str1[i];
			count++;
			i--;
			j--;
		}
		//若来自str1
		else if(dp[i][j]==dp[i-1][j]+1&&str1[i]!=str2[j]){
			ans[count]=str1[i];
			count++;
			i--;
		}
		//若来自str2
		else if(dp[i][j]==dp[i][j-1]+1&&str1[i]!=str2[j]){
			ans[count]=str2[j];
			count++;
			j--;
		}
	};
	//剩下的
	while(i>0){
		ans[count]=str1[i];
		count++;
		i--;
	};
	while(j>0){
		ans[count]=str2[j];
		count++;
		j--;
	};
	
	//输出结果
	for(i=count-1;i>=0;i--)cout<<ans[i];
	cout<<endl;
    //cout<<dp[len1][len2]
	return 0; 
} 
