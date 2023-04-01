//bfs与双端队列
//洛谷P4667 
#include<bits/stdc++.h>
using namespace std;
const int dir[4][2]={{-1,-1},{-1,1},{1,-1},{1,1}};//4个方向的位移
const int ab[4]={2,1,1,2};//4个元件期望的方向
const int cd[4][2]={{-1,-1},{-1,0},{0,-1},{0,0}};//4个元件编号的位移
int graph[505][505],dis[505][505];//dis记录节点到起点s的最短路径
struct P{
	int x,y,dis;
}u; 
int read_ch(){
	char c;
	while((c=getchar())!='/'&&c!='\\');//字符不是'/'或'\' 
	return c=='/'?1:2; 
};
int main(){
	int n,m;
	cin>>n>>m;
	memset(dis,0x3f,sizeof(dis));//初始化为最大值
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)graph[i][j]=read_ch();
	deque<P>dq;
	dq.push_back((P){1,1,0});
	dis[1][1]=0;
	while(!dq.empty()){
		u=dq.front();
		dq.pop_front();
		int nx,ny;
		for(int i=0;i<4;i++){
			nx=u.x+dir[i][0];
			ny=u.y+dir[i][1];
			int d=0;//边权
			d=(graph[u.x+cd[i][0]][u.y+cd[i][1]]!=ab[i]);//若方向不相等，则d=1
			if(nx&&ny&&nx<n+2&&ny<m+2&&dis[nx][ny]>dis[u.x][u.y]+d){
				//如果一个节点再次入队，那么距离应该更小
				//实际上，由于再次入队时，距离肯定更大，所以这里的作用是防止再次入队
				dis[nx][ny]=dis[u.x][u.y]+d;
				if(d==0)dq.push_front((P){nx,ny,dis[nx][ny]});//边权0，插到队头 
				else dq.push_back((P){nx,ny,dis[nx][ny]});//边权1，插到队尾
				if(nx==n+1&&ny==m+1)break; 
									//到终点退出，不退出也可以，队列为空自动退出 
			} 
		}
	};
	if(dis[n+1][m+1]!=0x3f3f3f3f)cout<<dis[n+1][m+1];
	else cout<<"NO SOLUTION";
	return 0;
}
