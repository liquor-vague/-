#include<iostream>
using namespace std;
typedef long long ll;
ll mul(ll a,ll b,ll m){
	a=a%m;
	b=b%m;
	ll res=0;
	while(b>0){
		//n&1��ͨ���������ж�n�����һλ�Ƿ�Ϊ1����n�Ƿ�Ϊ���� 
		if(b&1)res=(res+a)%m;
		a=(a+a)%m;
		b>>=1; 
	};
	return res;
};
int main(){
	ll a,b,m;
	//(a*b)%m
	cin>>a>>b>>m;
	cout<<mul(a,b,m);
	return 0;
}
