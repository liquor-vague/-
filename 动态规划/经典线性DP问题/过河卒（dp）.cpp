//洛谷p1002 
//这里用的是dp 
#include<bits/stdc++.h>
using namespace std;
const int N=25;
long long m[N][N],dp[N][N]={0};
//马的行走 
int dis1[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
int dis2[4][2]= {{2,0},{-2,0},{0,2},{0,-2}};
void horse(int hx,int hy);
void solve(int bx,int by);

int main(){
	int bx,by,hx,hy;
	cin>>bx>>by>>hx>>hy;
	//马所在的点也被马控制 
	m[hx][hy]=1;
	
	//标记马能到的位置
	horse(hx,hy);
	
	//0 0是否被马控制
	if (m[0][0]==1)dp[0][0]=0;
	else dp[0][0]=1; 
	
	//横纵坐标初始化
	for(int i=1;i<=bx;i++){
		if(m[i][0]!=1)dp[i][0]=dp[i-1][0];
		else dp[i][0]=0;
	};
	for(int i=1;i<=by;i++){
		if(m[0][i]!=1)dp[0][i]=dp[0][i-1];
		else dp[0][i]=0;
	};
	
	solve(bx,by);
	return 0;
}

void horse(int hx,int hy) {
	for(int i=0; i<4; i++) {
		if(dis2[i][1]==0) {
			for(int j=2; j<4; j++) {
				int x=hx+dis2[i][0]+dis1[j][0],y=hy+dis2[i][1]+dis1[j][1];
				if(x>=0&&y>=0)m[x][y]=1;
			}
		} else {
			for(int j=0; j<2; j++) {
				int x=hx+dis2[i][0]+dis1[j][0],y=hy+dis2[i][1]+dis1[j][1];
				if(x>=0&&y>=0)m[x][y]=1;
			}
		}
	}
};

void solve(int bx,int by){
	for(int i=1;i<=bx;i++){
		for(int j=1;j<=by;j++){
			if(m[i][j]!=1){
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
			else dp[i][j]=0;//被马控制 
		}
	};
	cout<<dp[bx][by];
}
