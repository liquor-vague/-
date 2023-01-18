//hdu1213
#include<cstdio>
using namespace std;
const int N=100005;
int s[N];
void init_set(int n);
int find(int x);
void merge_set(int x,int y);
int main() {
	int t,n,m;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		init_set(n);
		for(int i=1; i<=m; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			merge_set(x,y);
		};
		int ans=0;
		for(int i=1; i<=n; i++)if(s[i]==i)ans++;
		printf("%d",ans);
	}
	return 0;
};
void init_set(int n) { //初始化
	for(int i=1; i<=n; i++)s[i]=i;
};
int find(int x) {//查找 
	return x==s[x]?x:find(s[x]);
};
void merge_set(int x,int y) {//合并 
	x=find(x),y=find(y);
	if(x!=y)s[x]=s[y];//把x合并到y上，y的根成为x的根
}

