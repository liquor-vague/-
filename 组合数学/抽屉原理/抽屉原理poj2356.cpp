//poj2356
#include<iostream>
using namespace std;
const int N=1e5+5;
typedef long long ll;
ll arr[N];
ll sum[N];//求前缀和
ll pos[N];//抽屉对应的前缀和位置 
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		sum[i]=sum[i-1]+arr[i];
	};
	for(int i=1;i<=n;i++){
		if(sum[i]%n==0){
			cout<<i<<endl;
			for(int j=1;j<=i;j++)cout<<arr[j]<<endl;
			break;
		};
		if(pos[sum[i]%n]){
			cout<<i-pos[sum[i]%n]<<endl;
			for(int j=pos[sum[i]%n]+1;j<=i;j++)cout<<arr[j]<<endl;
			break;
		};
		pos[sum[i]%n]=i;
	}
	return 0;
}
