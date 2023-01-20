#include<cstdio>
using namespace std;
const int N=100005;
int s[N];
int d[N];
int ans;
void init_set(int n);
int find(int x);
void meget(int a,int b,int v);

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	init_set(n);
	ans=0;
	while(m--) {
		int a,b,v;
		scanf("%d%d%d",&a,&b,&v);
		a--;
		meget(a,b,v);
	};
	printf("%d",ans);
	return 0;
};

void init_set(int n) { //初始化
	for(int i=1; i<=n; i++) {
		s[i]=i;
		d[i]=0;
	}
};
int find(int x) { //查找，带权值的路径压缩，返回父节点
	if(x!=s[x]) {
		int tmp=s[x];
		s[x]=find(s[x]);//递归找父节点
		d[x]+=d[tmp];//权值更新到父节点的权值
	}
	return s[x];
};
void meget(int a,int b,int v) { //合并
	int roota=find(a),rootb=find(b);
	if(roota==rootb) {
		if(d[a]-d[b]!=v)ans++;
	} else {
		s[roota]=rootb;//更新父节点
		d[roota]=d[b]-d[a]+v;//更新权值
	}
}
