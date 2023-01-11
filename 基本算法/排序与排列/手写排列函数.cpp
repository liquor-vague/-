/*
用b[]记录新生成的全排列
用vis[]记录数是否被选过
*/
#include<iostream>
#include<algorithm>
using namespace std;
int arr[105],b[105],vis[105],n;
void dfs(int s,int n);
int main() {

	cin>>n;
	for(int i=1; i<=n; i++)cin>>arr[i];

	dfs(1,n);

	return 0;
};
void dfs(int s,int n) {
	if(s==n+1) {
		for(int i=1; i<=n; i++) {
			cout<<b[i]<<' ';
		}
		cout<<endl;
		return;
	}

	for(int i=1; i<=n; i++) {
		if(vis[i]==0) {
			vis[i]=1;
			b[s]=arr[i];
			dfs(s+1,n);
			vis[i]=0;
		}


	}

}
