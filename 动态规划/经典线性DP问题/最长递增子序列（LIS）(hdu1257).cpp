//hdu1257
//dp¹ö¶¯Êý×é 
#include<iostream>
using namespace std;
const int N=1005;
int arr[N],dp[N],mark[N];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>arr[i];
	for(int i=1;i<=n;i++){
		for(int j=n;j>0;j--){
			if(arr[j]>=arr[i]&&mark[j]==0){
				dp[j]=max(dp[j],dp[j-1]+1);
				mark[j]=1;
			}
		}
	;}
	cout<<dp[n];
	return 0;
}
