//poj1182
//还不是很能弄懂 
#include<cstdio>
using namespace std;
const int N=100005;
int s[N];
int d[N];//0:同类，1：吃，2：被吃 
int ans;
int n,k;
void init_set();
int find(int x);
void meget(int relation,int x,int y);

int main() {

	scanf("%d%d",&n,&k);
	init_set();
	ans=0;
	while(k--) {
		int relation,x,y;
		scanf("%d%d%d",&relation,&x,&y);
		//第二和第三类假话 
		if(x>n||y>n||(x==y&&relation==2))ans++;
		
		else meget(relation,x,y);

	}
	printf("%d",ans);
	return 0;
};

void init_set() {
	for(int i=1; i<=n; i++) {
		s[i]=i;
		d[i]=0;
	}
};

int find(int x) {
	if(x!=s[x]) {
		int tmp=s[x];//父节点 
		s[x]=find(tmp);//最后查找到根节点
		d[x]=(d[x]+d[tmp])%3;//权值变为根节点的权值 
	}
	return s[x];
}

void meget(int relation,int x,int y) {
	int rootx=find(x),rooty=find(y);
	if(rootx==rooty) {
		if((relation-1)!=(d[x]-d[y]+3)%3)
			ans++;
	}

	else {
		s[rootx]=rooty;
		d[rootx]=(d[y]-d[x]+relation-1)%3;
	}
}
