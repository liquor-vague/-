//ֻ�����б�������ʡ�ڴ�ռ�
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1005;
int dp[2][N],value[N],weight[N];
void solve(int n,int c);

int main() {
	int n,c;//nΪ��Ʒ������cΪ��������
	cin>>n>>c;
	for(int i=1; i<=n; i++)cin>>value[i];
	for(int i=1; i<=n; i++)cin>>weight[i];
	solve(n,c);
	return 0;
};
void solve(int n,int c) {
	int now=0,old=1;//nowָ�����ڴ���ģ�oldָ���ϴδ����
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=c; j++) {
			int tmp=weight[i];
			if(j>=weight[i]) dp[now][j]=max(dp[old][j],dp[old][j-tmp]+value[i]);
			else dp[now][j]=dp[old][j];
		};
		swap(now,old);
	};
	cout<<dp[old][c];
}
