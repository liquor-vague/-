//hdu1850
//��ķ����
//������cin��cout�ᳬʱ������ֻ����scanf��printf 

#include<bits/stdc++.h>
using namespace std;
const int N = 105;
typedef long long ll;
int a[N],n;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	while(~scanf("%d",&n)&&n) {
		int sum=0,ans=0;							//sumΪNim-sum��ansΪ��1�����з�����
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
			sum^=a[i];								//�����㣬��Nim-sum
		};

		if(sum==0)cout<<0<<endl;					//���ֱذ�
		else {
			for(int i=1; i<=n; i++)
				if((sum^a[i])<=a[i])ans++;			//�����1�����з���
			printf("%d\n",ans); 
		}
	}
	return 0;
}
