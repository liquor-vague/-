#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int olda[N],newa[N];
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>olda[i];
		newa[i]=olda[i];
	}
	sort(olda+1,olda+1+n);
	int cnt=n;
	//cnt=unique(olda+1,olda+1+n)-(olda+1);		//ȥ�أ�cnt��ȥ�غ������
	for(int i=1; i<=n; i++) {
		//lower_bound�ĸ�ʽ 
		newa[i]=lower_bound(olda+1,olda+1+n,newa[i])-olda;
	};
	for(int i=1; i<=n; i++)cout<<newa[i]<<" ";
	return 0;
}
