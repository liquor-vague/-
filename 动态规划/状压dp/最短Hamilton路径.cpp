//���Hamilton·����״ѹdp��
//acwing91
#include<bits/stdc++.h>
const int N = 21;
int n,dp[1<<N][N];
int dist[N][N];
using namespace std;
int main() {
	memset(dp,0x3f,sizeof(dp));						//��ʼ�����ֵ
	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>dist[i][j];						//����ͼ
	dp[1][0] = 0;									//��ʼ��������ֻ�е�0��������յ㶼��0
	for(int S=1; S<(1<<n); S++)						//��С������չ���󼯺ϣ�������S�Ķ����Ʊ�ʾ
		for(int j=0; j<n; j++)						//ö�ٵ�j
			if((S >> j) & 1)						//(1)
				for(int k=0; k<n; k++)				//ö�ٵ���j�ĵ�k , k���ڼ���S-j
					if((S^(1<<j))>>k&1)				//(2)k���ڼ���S-j, S-j��(1)��֤
						dp[S][j] = min(dp[S][j] , dp[S^(1<<j)][k] + dist[k][j]);
	cout<<dp[(1<<n)-1][n-1];						//�����·�����������еĵ㣬�յ���n-1
	return 0;
}
