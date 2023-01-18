//bfs+回溯 

#include<iostream>
#include<queue>
using namespace std;

struct node {
	int x,y;
};
const int N=305;
int n,m;
char map[N][N];
char pre[N][N];//用于记录前驱点
int visited[N][N]= {0};
char order[4]= {'D','L','R','U'};
int to[4][2]= {{1,0},{0,-1},{0,1},{-1,0}};

void bfs();
void print_road(int x,int y);

int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++)cin>>map[i][j];
	};
	bfs();
	return 0;
};

void bfs() {
	queue<node>q;
	node start;
	visited[1][1]=1;
	start.x=1,start.y=1;
	q.push(start);
	while(!q.empty()) {
		node now=q.front();
		q.pop();
		if(now.x==n&&now.y==m) {
			print_road(n,m);
			return;
		};
		
		for(int i=0; i<4; i++) {
			node next;
			next.x=now.x+to[i][0];
			next.y=now.y+to[i][1];

			//已搜索过或碰壁
			if(visited[next.x][next.y]==1||map[next.x][next.y]=='1')continue;
			//越界
			if(next.x<1||next.x>n||next.y<1||next.y>m)continue;

			visited[next.x][next.y]=1;
			pre[next.x][next.y]=order[i];
			q.push(next);
		}
	}

};

void print_road(int x,int y){
	if(x==1&&y==1)return;
	//回溯 
	if(pre[x][y]=='D')print_road(x-1,y);
	if(pre[x][y]=='U')print_road(x+1,y);
	if(pre[x][y]=='L')print_road(x,y+1);
	if(pre[x][y]=='R')print_road(x,y-1);
	cout<<pre[x][y];
}














