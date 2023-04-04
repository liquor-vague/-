#include<bits/stdc++.h>
using namespace std;
const int N=100010;
#define lowbit(x) ((x)&(-x))
int tree[N]= {0};
void update(int x,int d) { //单点修改：修改元素a[x]，a[x]=a[x]+d
	while(x<=N) {
		tree[x]+=d;
		x+=lowbit(x);//这是关键，后面能用lowbit求出的数都加上了相应值
	};
};
int sum(int x) {
	int ans=0;
	while(x>0) {
		ans+=tree[x];
		x-=lowbit(x);
	};
	return ans;
};
//以上为树状数组相关
int main() {
	int n;
	while(1) { 
		scanf("%d",&n);
		if(n==0)break;
		memset(tree,0,sizeof(tree));//只需要一个tree数组

		for(int i=1; i<=n; i++) { //区间修改
			int L,R;
			scanf("%d%d",&L,&R);
			update(L,1);//本题中d=1
			update(R+1,-1);
		};

		for(int i=1; i<=n; i++) {
			if(i!=n)printf("%d ",sum(i));
			else printf("%d\n",sum(i));
		};
	}
	return 0;
}
