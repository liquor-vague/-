//poj3107
//链式前向星存树
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
void add_edge(int u,int v){//链式前向量：加边u-v 
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
};
int n;
int d[N],ans[N],num=0,maxnum=1e9;
//d[u]是以u为根的子树的节点数量 
void dfs(int u,int father){//father是父节点 
	d[u]=1;
	int tmp=0;
	for(int i=head[u];i!=-1;i=edge[i].next){//遍历u的子节点 
		int v=edge[i].to;
		if(v==father)continue;//不递归父节点
		dfs(v,u);
		d[u]+=d[v]; 
		tmp=max(tmp,d[v]); //记录u的最大子树的节点数量 
	};
	tmp=max(tmp,n-d[u]);//tmp为u的最大连通块的节点数
	//以上计算出u的最大连通块 
	//下面统计教父
	//如果一个节点的最大连通块比其他节点的都小，它是疑似教父
	if(tmp<maxnum){//一个疑似教父 
		maxnum=tmp;//更新最小的连通块
		num=0;
		ans[++num]=u;//把教父记录在第一个位置 
	}
	else if(tmp==maxnum)ans[++num]=u;//疑似教父有多个，记录在后面 
};
int main(){
	scanf("%d",&n);
	init();
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);//互为根节点 
	};
	dfs(1,0);
	sort(ans+1,ans+1+num);
	for(int i=1;i<=num;i++)printf("%d ",ans[i]);
	return 0; 
}
