#include<cstdio>
using namespace std;
int node[1005];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int now=1,head=1,pre;
	for(int i=1;i<n;i++){
		node[i]=i+1;
	};
	node[n]=1;//±Õ»·
	while((n--)>1){
		for(int i=1;i<m;i++){
			pre=now;
			now=node[pre];
		};
		printf("%d ",now);
		node[pre]=node[now];
		now=node[now];
	};
	printf("%d",now);
	return 0;
}
