//洛谷p4155
#include<bits/stdc++.h>
using namespace std;
const int N=4e5+1;
int n,m;
struct warrior {
	int id,L,R;//战士的编号和左右区间
	bool operator<(const warrior b)const {
		return L<b.L;
	};//从小到大排序
} w[N+2];

int n2;
int go[N][20];//贪心和预计倍增步数

void init() {
	int next=1;		//用贪心求每个区间的下一个区间
	for(int i=1; i<=n2; i++) {
		while(next<=n2&&w[next].L<=w[i].R) {
			next++;//每个区间的下一个是右端点的最大区间
		};
		go[i][0]=next-1;//记录区间i的下一个区间
	};

	for(int i=1; (1<<i)<=n; i++) { //以log2的形式倍增
		for(int s=1; s<=n2; s++)
			go[s][i]=go[go[s][i-1]][i-1];
	};

}

int res[N];

void get_ans(int x) {			//从第x个战士开始
	int len=w[x].L+m,current=x,ans=1;
	for(int i=log2(N); i>=0; i--) {	//从最大的i开始找
		int position=go[current][i];
		if(position&&w[position].R<len) {
			ans+=1<<i;			//累加要跳过的区
			current=position;	//从新位置开始
		}
	};
	res[w[x].id]=ans+1;
}
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		w[i].id=i;
		cin>>w[i].L>>w[i].R;
		if(w[i].R<w[i].L) w[i].R+=m;//变成链
	};
	sort(w+1,w+1+n);			//按左端点排序
	n2=n;
	for(int i=1; i<=n; i++) { 	//将环拆成链
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
