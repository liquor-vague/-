/*��dp����Ӽ������⡣
��dp[i][j]=1ʱ����ʾS��ǰi��Ԫ�ش���һ���Ӽ��͵���j��
�𰸾���dp[i][M]
*/ 

#include<iostream>
using namespace std;
const int N=1005; 
int dp[N][N],s[N];
int main(){
	int t;//����S��Ԫ�صĸ���
	cin>>t;
	for(int i=1;i<=t;i++)cin>>s[i];
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)dp[i][0]=1;//ע���ʼ�������ֵΪ1 
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
