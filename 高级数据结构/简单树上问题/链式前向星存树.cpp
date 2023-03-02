//poj3107
//��ʽǰ���Ǵ���
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=50005;
struct Edge{
	int to,next;
}edge[N<<1];
int head[N],cnt=0;
void init(){
	for(int i=0;i<N;i++){
		edge[i].next=-1;
		head[i]=-1;
	};
	cnt=0;
};
void add_edge(int u,int v){//��ʽǰ�������ӱ�u-v 
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
};
int n;
int d[N],ans[N],num=0,maxnum=1e9;
//d[u]����uΪ���������Ľڵ����� 
void dfs(int u,int father){//father�Ǹ��ڵ� 
	d[u]=1;
	int tmp=0;
	for(int i=head[u];i!=-1;i=edge[i].next){//����u���ӽڵ� 
		int v=edge[i].to;
		if(v==father)continue;//���ݹ鸸�ڵ�
		dfs(v,u);
		d[u]+=d[v]; 
		tmp=max(tmp,d[v]); //��¼u����������Ľڵ����� 
	};
	tmp=max(tmp,n-d[u]);//tmpΪu�������ͨ��Ľڵ���
	//���ϼ����u�������ͨ�� 
	//����ͳ�ƽ̸�
	//���һ���ڵ�������ͨ��������ڵ�Ķ�С���������ƽ̸�
	if(tmp<maxnum){//һ�����ƽ̸� 
		maxnum=tmp;//������С����ͨ��
		num=0;
		ans[++num]=u;//�ѽ̸���¼�ڵ�һ��λ�� 
	}
	else if(tmp==maxnum)ans[++num]=u;//���ƽ̸��ж������¼�ں��� 
};
int main(){
	scanf("%d",&n);
	init();
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);//��Ϊ���ڵ� 
	};
	dfs(1,0);
	sort(ans+1,ans+1+num);
	for(int i=1;i<=num;i++)printf("%d ",ans[i]);
	return 0; 
}
