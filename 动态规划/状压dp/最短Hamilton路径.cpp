//最短Hamilton路径（状压dp）
//acwing91
#include<bits/stdc++.h>
const int N = 21;
int n,dp[1<<N][N];
int dist[N][N];
using namespace std;
int main() {
	memset(dp,0x3f,sizeof(dp));						//初始化最大值
	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>dist[i][j];						//输入图
	dp[1][0] = 0;									//开始：集合中只有点0，起点与终点都是0
	for(int S=1; S<(1<<n); S++)						//从小集合拓展到大集合，集合用S的二进制表示
		for(int j=0; j<n; j++)						//枚举点j
			if((S >> j) & 1)						//(1)
				for(int k=0; k<n; k++)				//枚举到达j的点k , k属于集合S-j
					if((S^(1<<j))>>k&1)				//(2)k属于集合S-j, S-j用(1)保证
						dp[S][j] = min(dp[S][j] , dp[S^(1<<j)][k] + dist[k][j]);
	cout<<dp[(1<<n)-1][n-1];						//输出：路径包含了所有的点，终点是n-1
	return 0;
}
