//���p1776
//�����Ʋ��+�������� 
#include<iostream>
using namespace std;
const int N=100005;
int v[N],w[N],m[N];
int dp[N];
int new_v[N],new_w[N],new_m[N];
int main(){
	int n,W;
	cin>>n>>W;
	for(int i=1;i<=n;i++)cin>>v[i]>>w[i]>>m[i];
	
	//�����Ʋ��
	int new_n=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m[i];j++){
			m[i]-=j;//��ȥ�Ѳ�ֵ� 
			new_v[++new_n]=j*v[i];//����Ʒ 
			new_w[new_n]=j*w[i];
		};
		if(m[i]){//���� 
			new_v[++new_n]=m[i]*v[i];
			new_w[new_n]=m[i]*w[i];
		}
	}
	
	//�������� 
	for(int i=1;i<=new_n;i++){
		for(int j=W;j>=new_w[i];j--){
			int tmp=new_w[i];
			dp[j]=max(dp[j],dp[j-tmp]+new_v[i]);
		}
	};
	
	cout<<dp[W];
	return 0;
}
