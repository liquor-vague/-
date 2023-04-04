//线段树模板
//洛谷p3372 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
#define lowbit(x) ((x)&(-x))
ll tree1[N],tree2[N];
void update1(ll x,ll d){
	while(x<=N){
		tree1[x]+=d;
		x+=lowbit(x);
	}; 
};
void update2(ll x,ll d){
	while(x<=N){
		tree2[x]+=d;
		x+=lowbit(x);
	}; 
};
ll sum1(ll x){
	ll ans=0;
	while(x>0){
		ans+=tree1[x];
		x-=lowbit(x);
	};
	return ans;
};
ll sum2(ll x){
	ll ans=0;
	while(x>0){
		ans+=tree2[x];
		x-=lowbit(x);
	};
	return ans;
};
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	ll old=0,tmp;
	for(int i=1;i<=n;i++){//初始化，差分数组原理 
	
		scanf("%lld",&tmp);
		update1(i,tmp-old);
	//?	
		update2(i,(i-1)*(tmp-old));
		old=tmp;
	};
	while(m--){//m个操作 
		ll q,L,R,d;
		scanf("%lld",&q);
		if(q==1){	//区间修改 	
			scanf("%lld%lld%lld",&L,&R,&d);
			update1(L,d);
			update1(R+1,-d);
			update2(L,(L-1)*d);
			update2(R+1,-d*R);
		}
		else{//区间查询
			 scanf("%lld%lld",&L,&R);
			 printf("%lld\n",R*sum1(R)-sum2(R)-(L-1)*sum1(L-1)+sum2(L-1));
			
		}
	};
	return 0;
}
