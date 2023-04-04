#include<bits/stdc++.h>
using namespace std;
const int N=100010;
#define lowbit(x) ((x)&(-x))
int tree[N]= {0};
void update(int x,int d) { //�����޸ģ��޸�Ԫ��a[x]��a[x]=a[x]+d
	while(x<=N) {
		tree[x]+=d;
		x+=lowbit(x);//���ǹؼ�����������lowbit�����������������Ӧֵ
	};
};
int sum(int x) {
	int ans=0;
	while(x>0) {
		ans+=tree[x];
		x-=lowbit(x);
	};
	return ans;
};
//����Ϊ��״�������
int main() {
	int n;
	while(1) { 
		scanf("%d",&n);
		if(n==0)break;
		memset(tree,0,sizeof(tree));//ֻ��Ҫһ��tree����

		for(int i=1; i<=n; i++) { //�����޸�
			int L,R;
			scanf("%d%d",&L,&R);
			update(L,1);//������d=1
			update(R+1,-1);
		};

		for(int i=1; i<=n; i++) {
			if(i!=n)printf("%d ",sum(i));
			else printf("%d\n",sum(i));
		};
	}
	return 0;
}
