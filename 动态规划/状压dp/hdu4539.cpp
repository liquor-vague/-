//状压dp
//hdu4539

#include<bits/stdc++.h>
using namespace std;
int mp[105][15];								//地图
int dp[105][200][200];
int n,m;
int sta[200];									//预算这一行的合法情况

int init_line(int n) {							//预算这一行的合法情况
	int M = 0;
	for(int i = 0; i<n; i++)
		if( (i&(i>>2))==0 && (i&(i<<2))==0 )	//左右间隔2的位置没人，即为合法 
			sta[M++]=i;
	return M;
}

int count_line(int i,int x) {					//计算第i行士兵数量
	int sum = 0;
	for(int j = m-1; j>=0; j--) {				//x是预算过的合法安排
		if(x&1)sum+=mp[i][j];					//将x与地形匹配
		x = x>>1;
	};
	return sum;
}

int main() {
	while(~scanf("%d%d",&n,&m)) {
		int M = init_line(1<<m);				//预算这一行的合法情况
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				scanf("%d",&mp[i][j]);			//输入地图

		int ans = 0;
		memset(dp,0,sizeof(dp));
		for(int i=0; i<n; i++)					//第i行
			for(int j=0; j<M; j++)				//枚举第i行的合法安排
				for(int k=0; k<M; k++) {		//枚举第i-1行的合法安排

					if(i==0) {					//计算第1行
						dp[i][j][k] = count_line(i,sta[j]);
						ans = max(ans,dp[i][j][k]);
						continue;
					}

					if( (sta[j]&(sta[k]>>1)) || (sta[j]&(sta[k]<<1)))
						continue;				//第i行和第i-1行冲突

					int tmp = 0;
					for(int p=0; p<M; p++) {		//枚举第i-2行合法状态
						if( (sta[p]&(sta[k]>>1)) || (sta[p]&(sta[k]<<1)))continue;
						//第i-1行和第i-2行冲突
						if(sta[j]&sta[p])continue;
						//第i行和第i-2行冲突
						tmp = max(tmp,dp[i-1][k][p]);
						//从第i-1行递推到第i行
					}
					dp[i][j][k] = tmp + count_line(i,sta[j]);
					//加上第i行士兵的数量
					ans = max(ans,dp[i][j][k]);

				};

		printf("%d\n",ans);
	}
	return 0;
}
