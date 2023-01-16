//poj2227
//���ú�ˮ��䣬�����ܵ�������м���
//ע�ⳤ�Ϳ����������ϵĶ�Ӧ 
#include<cstdio>
#include<queue>
using namespace std;
const int N=305;
int W,H,height[N][N],mark[N][N]= {0};
struct node {
	int x,y,h;
	
	//�����������ȼ�����
	friend bool operator<(node a,node b) {
		//>Ϊ��С��������
		return a.h>b.h;
	}

};
priority_queue<node>q;
//4������
int direction[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};

void initialization() {
    while(!q.empty()) q.pop();
	//�Ƚ��߽���뵽������
	node temp;
	for(int i=1; i<=H; i++) {
		for(int j=1; j<=W; j++) {
			if(i==1||j==1||i==H||j==W) {
				mark[i][j]=1;
				temp.x=i,temp.y=j,temp.h=height[i][j];
				q.push(temp);
			}
		}
	}
};

void bfs() {
	initialization();
	int ans=0;
	node tmp,max;
	while(!q.empty()) {
		max=q.top();
		q.pop();
		for(int i=0; i<4; i++) {
			//���Ҹ���ש��߶� 
			int nx=max.x+direction[i][0];
			int ny=max.y+direction[i][1];
			if(nx>=1&&nx<=H&&ny>=1&&ny<=W&&!mark[nx][ny]) {
				mark[nx][ny]=1;
				tmp.x=nx,tmp.y=ny,tmp.h=height[nx][ny];
				if(tmp.h<max.h)ans+=(max.h-tmp.h),tmp.h=max.h;
				q.push(tmp);
			}
		}
	}
	printf("%d",ans);
};

int main() {
	scanf("%d%d",&W,&H);
	for(int i=1; i<=H; i++)
		for(int j=1; j<=W; j++)scanf("%d",&height[i][j]);
	bfs();
	return 0;
};
