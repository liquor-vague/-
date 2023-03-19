//������L2-001 
//Dijkstra�㷨����̰���㷨���Ż� 
#include<bits/stdc++.h>
using namespace std;
void Dijkstra();
void print(int t);
#define max 505
#define MAX 100000
const int INF=1e9+7;
int n,m,s,d;
int a,b,c;
int people[max];//��Ԯ����Ŀ
int graph[max][max];//�ڽӾ���graph
int dis[max];//�����ʼ�ڵ��������ڵ�����·��
int vis[max];//����Ƿ�洢��
int num[MAX];//�洢����ʼ�ڵ��������ڵ��ټ�������Ա�������
int cnt[MAX];//�洢����ʼ�ڵ��������ڵ�����·����Ŀ
int way[MAX];//�洢ǰ���ڵ�

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
	cnt[s]=1;//��ǳ�ʼ�ڵ�
	way[s]=s;

	for(int i=0; i<n; i++) {
		dis[i]=graph[s][i];//��dis�����ʼ��Ϊ���ͼ�еĳ���
	};
	//�������·����ѭ��
	for(int i=0; i<n; i++) {

		int min_dis = INF; // �洢����㵽����δ�����ʽڵ��е���̾���
		int mid = -1; // �洢��̾���ڵ�ı��

		for(int j=0; j<n; j++) {
			//����ڵ�δ������
			if(vis[j]==0&&min_dis>dis[j]) {
				min_dis=dis[j];
				mid=j;
			}
		};
		
		if(mid==-1)break;
		vis[mid]=1;
		
		//��midΪ�м�ڵ㣬�ٱ������нڵ�
		for(int j=0; j<n; j++) {
			if(vis[j]==0&&dis[j]>dis[mid]+graph[mid][j]) {
				//���¾���֮��
				dis[j]=dis[mid]+graph[mid][j];
				//�ڵ�mid���ڵ�j����һ�����̵�·��
				cnt[j]=cnt[mid];
				//���½ڵ�j�ľ�Ԯ����Ŀ
				num[j]=num[mid]+people[j];
				//��¼�ڵ�mid
				way[j]=mid;
			} 
			else if(vis[j]==0&&dis[j]==dis[mid]+graph[mid][j]) {
				//��j�����·����Ŀ���ϵ�mid�����·����Ŀ
				cnt[j]+=cnt[mid];
				if(num[j]<num[mid]+people[j]) {
					//���½ڵ�j��Ԯ����Ŀ
					num[j]=num[mid]+people[j];
					//��¼�ڵ�mid
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
