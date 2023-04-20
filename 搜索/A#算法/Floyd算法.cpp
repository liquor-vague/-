//������L2-044��������
//Floyd�㷨����dijkstra�㷨ԭ�����ƣ�������û��ô����
#include<bits/stdc++.h>
using namespace std;
const int N=510;
int g[N][N],sex[N],d[N];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) { //��ʼ��
		for(int j=1; j<=n; j++) {
			if(i==j)g[i][j]=0;//�Լ����Լ��ľ���Ϊ0
			else g[i][j]=1e9;
		}
	};
	for(int i=1; i<=n; i++) {
		char op;
		int k;
		scanf(" %c %d",&op,&k);
		if(op=='F')sex[i]=1;//Ů��
		else sex[i]=2;//����
		for(int j=1; j<=k; j++) {
			int a,b;
			scanf("%d:%d",&a,&b);
			g[i][a]=b;//��i���˶�a�ľ����Ϊb
		}
	};
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);//�ҳ�������С�����
			}
		}
	};
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(sex[i]!=sex[j])//����
				d[i]=max(d[i],g[j][i]);//���������
		}
	};
	int d1=1e9,d2=1e9;//d1��ʾ�ж�Ů�ľ��룬d2��ʾŮ���еľ���
	for(int i=1; i<=n; i++) {
		if(sex[i]==2)d1=min(d1,d[i]);//���ж�Ů����С����
		else d2=min(d2,d[i]);
	};

	vector<int>a,b;
	for(int i=1; i<=n; i++) { //Ů�ԵĴ������˺����ԵĴ�������
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
