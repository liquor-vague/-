#include<iostream>
#include<string.h>
using namespace std;
const int N=10005;
int a[N],d[N];//a是气球,d是差分数组
int main(){
	int n=1;
	while(cin>>n&&n!=0){
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++){
			int L,R;
			cin>>L>>R;
			d[L]++;
			d[R+1]--;
		};
		for(int i=1;i<=n;i++){
			a[i]=a[i-1]+d[i];
			cout<<a[i]<<" ";
		};
		cout<<endl;
	};
	return 0;
} 
