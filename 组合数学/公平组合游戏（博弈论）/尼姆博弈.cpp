//hdu1850
//尼姆博弈
//这里用cin和cout会超时，所以只能用scanf和printf 

#include<bits/stdc++.h>
using namespace std;
const int N = 105;
typedef long long ll;
int a[N],n;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	while(~scanf("%d",&n)&&n) {
		int sum=0,ans=0;							//sum为Nim-sum，ans为第1步可行方案数
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
			sum^=a[i];								//异或计算，求Nim-sum
		};

		if(sum==0)cout<<0<<endl;					//先手必败
		else {
			for(int i=1; i<=n; i++)
				if((sum^a[i])<=a[i])ans++;			//计算第1步可行方案
			printf("%d\n",ans); 
		}
	}
	return 0;
}
