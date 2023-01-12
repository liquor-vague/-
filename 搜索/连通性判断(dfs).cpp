//洛谷p8662 
//蓝桥杯 dfs;
#include<iostream>
using namespace std;
const int N=1005;
char map[N][N];
int vis[N][N]= {0};
int direction[4][2] {{1,0},{-1,0},{0,1},{0,-1}};
int flag;
void dfs(int x,int y);

int main() {
	int n,ans=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin>>map[i][j];
		}
	};

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(map[i][j]=='#'&&vis[i][j]==0) {
				flag=0;//假设岛会被淹没 
				dfs(i,j);
				if(flag==0)ans++;//统计被淹没的岛数 

			}

		};
	
	};
		cout<<ans;
	return 0;
};
void dfs(int x,int y) {
	vis[x][y]=1;
	if(map[x-1][y]=='#'&&map[x][y-1]=='#'&&map[x+1][y]=='#'&&map[x][y+1]=='#') {
		flag=1;//上下左右均为陆地，岛为高地,不会被淹没 
	};
	for(int i=0; i<4; i++) {
		int nx=x+direction[i][0],ny=y+direction[i][1];
		if(vis[nx][ny]==0&&map[nx][ny]=='#') {
			dfs(nx,ny);
		}
	}
}
