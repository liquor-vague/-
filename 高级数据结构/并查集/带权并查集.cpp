#include<cstdio>
using namespace std;
const int N=100005;
int s[N];
int d[N];
int ans;
void init_set(int n);
int find(int x);
void meget(int a,int b,int v);

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	init_set(n);
	ans=0;
	while(m--) {
		int a,b,v;
		scanf("%d%d%d",&a,&b,&v);
		a--;
		meget(a,b,v);
	};
	printf("%d",ans);
	return 0;
};

void init_set(int n) { //��ʼ��
	for(int i=1; i<=n; i++) {
		s[i]=i;
		d[i]=0;
	}
};
int find(int x) { //���ң���Ȩֵ��·��ѹ�������ظ��ڵ�
	if(x!=s[x]) {
		int tmp=s[x];
		s[x]=find(s[x]);//�ݹ��Ҹ��ڵ�
		d[x]+=d[tmp];//Ȩֵ���µ����ڵ��Ȩֵ
	}
	return s[x];
};
void meget(int a,int b,int v) { //�ϲ�
	int roota=find(a),rootb=find(b);
	if(roota==rootb) {
		if(d[a]-d[b]!=v)ans++;
	} else {
		s[roota]=rootb;//���¸��ڵ�
		d[roota]=d[b]-d[a]+v;//����Ȩֵ
	}
}
