//״ѹdp
//hdu4539

#include<bits/stdc++.h>
using namespace std;
int mp[105][15];								//��ͼ
int dp[105][200][200];
int n,m;
int sta[200];									//Ԥ����һ�еĺϷ����

int init_line(int n) {							//Ԥ����һ�еĺϷ����
	int M = 0;
	for(int i = 0; i<n; i++)
		if( (i&(i>>2))==0 && (i&(i<<2))==0 )	//���Ҽ��2��λ��û�ˣ���Ϊ�Ϸ� 
			sta[M++]=i;
	return M;
}

int count_line(int i,int x) {					//�����i��ʿ������
	int sum = 0;
	for(int j = m-1; j>=0; j--) {				//x��Ԥ����ĺϷ�����
		if(x&1)sum+=mp[i][j];					//��x�����ƥ��
		x = x>>1;
	};
	return sum;
}

int main() {
	while(~scanf("%d%d",&n,&m)) {
		int M = init_line(1<<m);				//Ԥ����һ�еĺϷ����
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				scanf("%d",&mp[i][j]);			//�����ͼ

		int ans = 0;
		memset(dp,0,sizeof(dp));
		for(int i=0; i<n; i++)					//��i��
			for(int j=0; j<M; j++)				//ö�ٵ�i�еĺϷ�����
				for(int k=0; k<M; k++) {		//ö�ٵ�i-1�еĺϷ�����

					if(i==0) {					//�����1��
						dp[i][j][k] = count_line(i,sta[j]);
						ans = max(ans,dp[i][j][k]);
						continue;
					}

					if( (sta[j]&(sta[k]>>1)) || (sta[j]&(sta[k]<<1)))
						continue;				//��i�к͵�i-1�г�ͻ

					int tmp = 0;
					for(int p=0; p<M; p++) {		//ö�ٵ�i-2�кϷ�״̬
						if( (sta[p]&(sta[k]>>1)) || (sta[p]&(sta[k]<<1)))continue;
						//��i-1�к͵�i-2�г�ͻ
						if(sta[j]&sta[p])continue;
						//��i�к͵�i-2�г�ͻ
						tmp = max(tmp,dp[i-1][k][p]);
						//�ӵ�i-1�е��Ƶ���i��
					}
					dp[i][j][k] = tmp + count_line(i,sta[j]);
					//���ϵ�i��ʿ��������
					ans = max(ans,dp[i][j][k]);

				};

		printf("%d\n",ans);
	}
	return 0;
}
