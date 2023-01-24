#include<iostream>
using namespace std;
const int N=100005;
int sum[N];
int fib(int x){
	if(sum[x]!=0)return sum[x];
	else{
		sum[1]=sum[2]=1;
		for(int i=3;i<=x;i++){
			sum[i]=sum[i-1]+sum[i-2];
		}
	}
	return sum[x];
}
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	cout<<fib(n);
	return 0; 
} 
