//天梯赛L2-001 
//Dijkstra算法属于贪心算法的优化 
#include<bits/stdc++.h>
using namespace std;
void Dijkstra();
void print(int t);
#define max 505
#define MAX 100000
const int INF=1e9+7;
int n,m,s,d;
int a,b,c;
int people[max];//救援队数目
int graph[max][max];//邻接矩阵graph
int dis[max];//存从起始节点至其他节点的最短路径
int vis[max];//标记是否存储过
int num[MAX];//存储从起始节点至其他节点召集的消防员最大总数
int cnt[MAX];//存储从起始节点至其他节点的最短路径数目
int way[MAX];//存储前驱节点

int main() {
	scanf("%d%d%d%d",&n,&m,&s,&d);
	for(int i=0;i<n;i++)scanf("%d",&people[i]);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(i==j)graph[i][j]=0;
			else graph[i][j]=INF;
		}
	};
	for(int i=0; i<m; i++) {
		scanf("%d%d%d",&a,&b,&c);
		graph[a][b]=c;
		graph[b][a]=c;
	};

	Dijkstra();

	printf("%d %d\n",cnt[d],num[d]);
	print(d);
	return 0;
};
void Dijkstra() {
	dis[s]=0;
	num[s]=people[s];
	cnt[s]=1;//标记初始节点
	way[s]=s;

	for(int i=0; i<n; i++) {
		dis[i]=graph[s][i];//将dis数组初始化为最初图中的长度
	};
	//更新最短路径的循环
	for(int i=0; i<n; i++) {

		int min_dis = INF; // 存储从起点到其他未被访问节点中的最短距离
		int mid = -1; // 存储最短距离节点的编号

		for(int j=0; j<n; j++) {
			//如果节点未被访问
			if(vis[j]==0&&min_dis>dis[j]) {
				min_dis=dis[j];
				mid=j;
			}
		};
		
		if(mid==-1)break;
		vis[mid]=1;
		
		//以mid为中间节点，再遍历所有节点
		for(int j=0; j<n; j++) {
			if(vis[j]==0&&dis[j]>dis[mid]+graph[mid][j]) {
				//更新距离之和
				dis[j]=dis[mid]+graph[mid][j];
				//节点mid到节点j存在一条更短的路径
				cnt[j]=cnt[mid];
				//更新节点j的救援队数目
				num[j]=num[mid]+people[j];
				//记录节点mid
				way[j]=mid;
			} 
			else if(vis[j]==0&&dis[j]==dis[mid]+graph[mid][j]) {
				//到j的最短路径数目加上到mid的最短路径数目
				cnt[j]+=cnt[mid];
				if(num[j]<num[mid]+people[j]) {
					//更新节点j救援队数目
					num[j]=num[mid]+people[j];
					//记录节点mid
					way[j]=mid;
				}
			}
		}
	}
};
void print(int t){
	if(t==s){
		printf("%d",s);
		return;
	};
	print(way[t]);
	printf(" %d",t);
}
