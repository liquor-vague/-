//쳲��������ݹ鵫��¼����������ظ�����
#include<iostream>
using namespace std;
const int N =100005;
int sum[N];
int fib(int x) {
	if(x==1||x==2)return 1;
	if(sum[x]!=0)return sum[x];
	sum[x]=fib(x-1)+fib(x-2);
	return sum[x];
}
int main() {
	ios::sync_with_stdio(0);
	int n;//�����n�� 
	cin>>n;
	cout<<fib(n);
	return 0;
}
