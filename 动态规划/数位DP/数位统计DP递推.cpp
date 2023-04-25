//洛谷2602 
#include<iostream>
using namespace std;
typedef long long ll;
const int N=15;
ll cnta[N],cntb[N];
ll ten[N],dp[N];
int num[N];

void init();
void solve(ll x,ll *cnt);

int main(){
	init();
	ll a,b;
	cin>>a>>b;
	solve(a-1,cnta),solve(b,cntb);
	for(int i=0;i<=9;i++)cout<<cntb[i]-cnta[i]<<" ";
	return 0;
};
void init(){
	ten[0]=1;//预计算dp[]
	for(int i=1;i<=N;i++){
		dp[i]=i*ten[i-1];
		ten[i]=10*ten[i-1];
	};
};
void solve(ll x,ll *cnt){
	int len=0;
	while(x){
		num[++len]=x%10;//将数拆分 
		x=x/10;
	};
	for(int i=len;i>0;i--){
		for(int j=0;j<=9;j++)cnt[j]+=dp[i-1]*num[i];
		for(int j=0;j<num[i];j++)cnt[j]+=ten[i-1];//特判最高位比num[i]小的数字
		ll num2=0;
		for(int j=i-1;j>=1;j--)num2=num2*10+num[j];
		cnt[num[i]]+=num2+1;
		cnt[0]-=ten[i-1];
	}
}
