//�Թ�Сͼ����
//����������ռ�ô����ռ䣬��Ϊÿ�����϶��洢������·��
#include<cstdio>
#include<string>
#include<queue>
#include<iostream>
using namespace std;

struct node {
	int x,y;
	string path;//��¼�����(0,0)��(x,y)������·��
};

char map[35][55];//��ͼ
int visited[35][55]= {0}; //����Ƿ���ʹ���1�����ѷ��ʣ�0����δ����
char order[4]= {'D','L','R','U'}; //�ֵ���
int to[4][2]= {{1,0},{0,-1},{0,1},{-1,0}}; //�ĸ�����Ҫ���ֵ���ķ���һһ��Ӧ

int n,m;//�Թ��ĳ���

void bfs();

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)cin>>map[i][j];
	//������scanf���У������������ʽ������
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

		//���յ�
		if(now.x==n&&now.y==m) {
			cout<<now.path;
			//������printf�ᱨ��
			//printf("%s",now.path);
		}

		//���ھ���ɢ
		for(int i=0; i<4; i++) {
			node next;
			next.x=now.x+to[i][0];
			next.y=now.y+to[i][1];

			//���������


			//Խ��
			if(next.x<0||next.x<0||next.x>n||next.y>m)continue;
			//���߹�������
			if(visited[next.x][next.y]==1||map[next.x][next.y]=='1')continue;

			visited[next.x][next.y]=1;
			next.path=now.path+order[i];
			q.push(next);
		}
	}
};

