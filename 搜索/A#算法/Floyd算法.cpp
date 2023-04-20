//天梯赛L2-044大众情人
//Floyd算法，和dijkstra算法原理类似，但条件没那么苛刻
#include<bits/stdc++.h>
using namespace std;
const int N=510;
int g[N][N],sex[N],d[N];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) { //初始化
		for(int j=1; j<=n; j++) {
			if(i==j)g[i][j]=0;//自己对自己的距离为0
			else g[i][j]=1e9;
		}
	};
	for(int i=1; i<=n; i++) {
		char op;
		int k;
		scanf(" %c %d",&op,&k);
		if(op=='F')sex[i]=1;//女生
		else sex[i]=2;//男生
		for(int j=1; j<=k; j++) {
			int a,b;
			scanf("%d:%d",&a,&b);
			g[i][a]=b;//第i个人对a的距离感为b
		}
	};
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);//找出二者最小距离感
			}
		}
	};
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(sex[i]!=sex[j])//异性
				d[i]=max(d[i],g[j][i]);//找最大距离感
		}
	};
	int d1=1e9,d2=1e9;//d1表示男对女的距离，d2表示女对男的距离
	for(int i=1; i<=n; i++) {
		if(sex[i]==2)d1=min(d1,d[i]);//找男对女的最小距离
		else d2=min(d2,d[i]);
	};

	vector<int>a,b;
	for(int i=1; i<=n; i++) { //女性的大众情人和男性的大众情人
		if(sex[i]==1&&d[i]==d2)a.push_back(i);
		if(sex[i]==2&&d[i]==d1)b.push_back(i);
	};
	printf("%d",a[0]);
	for(int i=1; i<a.size(); i++) {
		printf(" %d",a[i]);
	};
	printf("\n");
	
	printf("%d",b[0]);
	for(int i=1; i<b.size(); i++) {
		printf(" %d",b[i]);
	};
	printf("\n");
	return 0;
}
