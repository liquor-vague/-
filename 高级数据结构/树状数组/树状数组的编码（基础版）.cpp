#include<bits/stdc++.h>
using namespace std;
const int N=1005;
#define lowbit(x) ((x)&(-x))
int tree[N]={0};
void update(int x,int d){//单点修改：修改元素a[x]，a[x]=a[x]+d 
	while(x<=N){
		tree[x]+=d;
		x+=lowbit(x);//这是关键，后面能用lowbit求出的数都加上了相应值 
	}; 
};
int sum(int x){
	int ans=0;
	while(x>0){
		ans+=tree[x];
		x-=lowbit(x);
	};
	return ans;
};
//以上为树状数组相关
int a[11]={0,1,2,3,4,5,6,7,8,9,10};//注意：a[0]不用 
int main(){
	for(int i=1;i<=10;i++)update(i,a[i]);
	cout<<"old:[5,8]="<<sum(8)-sum(4)<<endl;
	update(5,100);
	cout<<"new:[5,8]="<<sum(8)-sum(4)<<endl;
	return 0; 
}
