//迷宫小图做法
//这种做法会占用大量空间，因为每个点上都存储了完整路径
#include<cstdio>
#include<string>
#include<queue>
#include<iostream>
using namespace std;

struct node {
	int x,y;
	string path;//记录从起点(0,0)到(x,y)的完整路径
};

char map[35][55];//地图
int visited[35][55]= {0}; //标记是否访问过，1代表已访问，0代表未访问
char order[4]= {'D','L','R','U'}; //字典序
int to[4][2]= {{1,0},{0,-1},{0,1},{-1,0}}; //四个方向，要与字典序的方向一一对应

int n,m;//迷宫的长宽

void bfs();

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)cin>>map[i][j];
	//这里用scanf不行，可能是输入格式有问题
	//scanf("%c",&map[i][j]);
	bfs();
	return 0;
};

void bfs() {

	queue<node>q;
	node start;
	visited[1][1]=1;
	start.x=1,start.y=1;
	start.path="";
	q.push(start);


	while(!q.empty()) {
		node now=q.front();
		q.pop();

		//到终点
		if(now.x==n&&now.y==m) {
			cout<<now.path;
			//这里用printf会报错
			//printf("%s",now.path);
		}

		//向邻居扩散
		for(int i=0; i<4; i++) {
			node next;
			next.x=now.x+to[i][0];
			next.y=now.y+to[i][1];

			//标记搜索过


			//越界
			if(next.x<0||next.x<0||next.x>n||next.y>m)continue;
			//已走过或碰壁
			if(visited[next.x][next.y]==1||map[next.x][next.y]=='1')continue;

			visited[next.x][next.y]=1;
			next.path=now.path+order[i];
			q.push(next);
		}
	}
};

