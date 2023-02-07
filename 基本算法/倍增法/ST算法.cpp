//��ʼ�����Ӷ�ΪO(nlogn)�����Ҹ��Ӷ�ΪO(1)
//�о����Ҳ��������˹����
#include<iostream>
#include<cmath>
using namespace std;
const int N=200005;
int n,m;
int arr[N],dp_max[N][22],dp_min[N][21];
//dp[i][j]��������һ���������ֵ����˵�Ϊi������Ϊ2^j
//��ζ������Ͻ[i,i+2^j-1]
int LOG2[N];
int st_query(int L,int R);
void st_init();

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>arr[i];
	st_init();
	for(int i=1; i<=m; i++) {
		int L,R;
		cin>>L>>R;
		int ans=st_query(L,R);
		cout<<ans<<endl;
	};
	return 0;
};
//Ԥ����
void st_init() {
	LOG2[0]=-1;

	//�ֶ���log2
	for(int i=1; i<=N; i++)LOG2[i]=LOG2[i>>1]+1;
	//��ʼ�����䳤��Ϊ1
	for(int i=1; i<=n; i++) {
		dp_max[i][0]=arr[i];
		dp_min[i][0]=arr[i];
	};

	//�ɱ�����������η���2^p<=n
	int p=log2(n);

	//�������㣬��С���䵽�����䣬����
	for(int k=1; k<=p; k++) {

		for(int s=1; s+(1<<k)<=n+1; s++) { //n+1�Ƿ�ֹ���
			//λ����
			dp_max[s][k]=max(dp_max[s][k-1],dp_max[s+(1<<k-1)][k-1]);
			dp_min[s][k]=min(dp_min[s][k-1],dp_min[s+(1<<k-1)][k-1]);
		}
	}
};
int st_query(int L,int R) {
	int k=log2(R-L+1);
	//�������
	int x=max(dp_max[L][k],dp_max[R-(1<<k)+1][k]);
	//������С
	int y= min(dp_min[L][k],dp_min[R-(1<<k)+1][k]);
	//�����
	return x-y;
}
