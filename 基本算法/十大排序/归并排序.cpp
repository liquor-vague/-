#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1005;
typedef long long ll;
ll a[N],b[N],cnt=0;//cnt是记录逆序对数

void merge(ll l,ll mid,ll r) {
	ll i=l,j=mid+1,t=0;
	while(i<=mid&&j<=r) {
		if(a[i]>a[j]) {
			b[t++]=a[j++];
			cnt+=mid-i+1;
		} else b[t++]=a[i++];
	};
	//一个子序列中的数处理完了，另一个还没有，把剩下的复制过来
	while(i<=mid) b[t++]=a[i++];
	while(j<=r)b[t++]=a[j++];
	for(i=0; i<t; i++)a[l+i]=b[i]; //把排序好的b[]复制回a[]
};
void merge_sort(ll l,ll r) { //分成两个子序列
	if(l<r) {//l==r时序列中只有一个元素 
		ll mid=(l+r)/2;
		merge_sort(l,mid);
		merge_sort(mid+1,r);
		merge(l,mid,r);
	}
};

int main() {
	ll n,k;
	cin>>n>>k;
	for(ll i=0; i<n; i++)cin>>a[i];
	merge_sort(0,n-1);
	if(cnt<=k)cout<<"0";
	else cout<<cnt-k;
	return 0;
}
