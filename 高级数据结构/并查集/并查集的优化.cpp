//hdu1213
//�����˸߶������Ż��˺ϲ�
#include<cstdio>
using namespace std;
const int N=100005;
int s[N],height[N];
void init_set(int n);
int find(int x);
void merge_set(int x,int y);
int main() {
	int t,n,m;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		init_set(n);
		for(int i=1; i<=m; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			merge_set(x,y);
		};
		int ans=0;
		for(int i=1; i<=n; i++)if(s[i]==i)ans++;
		printf("%d",ans);
	}
	return 0;
};
void init_set(int n) { //��ʼ��
	for(int i=1; i<=n; i++) {
		s[i]=i;
		height[i]=0;
	}
};
int find(int x) {//����
	return x==s[x]?x:find(s[x]);
};
void merge_set(int x,int y) {//�ϲ�
	x=find(x),y=find(y);
	if(height[x]==height[y]) {
		height[x]=height[x]+1;//�ϲ������ĸ߶�+1
		s[y]=x;
	} else {
		//�Ѱ����ϲ���������
		if(height[x]<height[y])s[x]=y;
		else s[y]=x;

	}
}

