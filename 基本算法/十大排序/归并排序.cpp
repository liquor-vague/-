#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1005;
typedef long long ll;
ll a[N],b[N],cnt=0;//cnt�Ǽ�¼�������

void merge(ll l,ll mid,ll r) {
	ll i=l,j=mid+1,t=0;
	while(i<=mid&&j<=r) {
		if(a[i]>a[j]) {
			b[t++]=a[j++];
			cnt+=mid-i+1;
		} else b[t++]=a[i++];
	};
	//һ���������е����������ˣ���һ����û�У���ʣ�µĸ��ƹ���
	while(i<=mid) b[t++]=a[i++];
	while(j<=r)b[t++]=a[j++];
	for(i=0; i<t; i++)a[l+i]=b[i]; //������õ�b[]���ƻ�a[]
};
void merge_sort(ll l,ll r) { //�ֳ�����������
	if(l<r) {//l==rʱ������ֻ��һ��Ԫ�� 
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
