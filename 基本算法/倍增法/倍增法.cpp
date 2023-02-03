//���p4155
#include<bits/stdc++.h>
using namespace std;
const int N=4e5+1;
int n,m;
struct warrior {
	int id,L,R;//սʿ�ı�ź���������
	bool operator<(const warrior b)const {
		return L<b.L;
	};//��С��������
} w[N+2];

int n2;
int go[N][20];//̰�ĺ�Ԥ�Ʊ�������

void init() {
	int next=1;		//��̰����ÿ���������һ������
	for(int i=1; i<=n2; i++) {
		while(next<=n2&&w[next].L<=w[i].R) {
			next++;//ÿ���������һ�����Ҷ˵���������
		};
		go[i][0]=next-1;//��¼����i����һ������
	};

	for(int i=1; (1<<i)<=n; i++) { //��log2����ʽ����
		for(int s=1; s<=n2; s++)
			go[s][i]=go[go[s][i-1]][i-1];
	};

}

int res[N];

void get_ans(int x) {			//�ӵ�x��սʿ��ʼ
	int len=w[x].L+m,current=x,ans=1;
	for(int i=log2(N); i>=0; i--) {	//������i��ʼ��
		int position=go[current][i];
		if(position&&w[position].R<len) {
			ans+=1<<i;			//�ۼ�Ҫ��������
			current=position;	//����λ�ÿ�ʼ
		}
	};
	res[w[x].id]=ans+1;
}
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		w[i].id=i;
		cin>>w[i].L>>w[i].R;
		if(w[i].R<w[i].L) w[i].R+=m;//�����
	};
	sort(w+1,w+1+n);			//����˵�����
	n2=n;
	for(int i=1; i<=n; i++) { 	//���������
		n2++;
		w[n2]=w[i];
		w[n2].L=w[i].L+m;
		w[n2].R=w[i].R+m;
	};
	init();
	for(int i=1; i<=n; i++)get_ans(i);
	for(int i=1; i<=n; i++)printf("%d ",res[i]);
	return 0;
}
