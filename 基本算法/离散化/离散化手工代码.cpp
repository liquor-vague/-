#include<iostream>
#include<algorithm>
using namespace std;
const int N=1005;
struct data{
	int value;
	int id;
}olda[N];
int newa[N];

bool cmp(data x,data y){
	return x.value<y.value;
};

int main(){
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>olda[i].value;
		olda[i].id=i;
	};
	
	sort(olda+1,olda+1+n,cmp);
	
	for(int i=1;i<=n;i++){
		newa[olda[i].id]=i;//��ɢ�������ֵ 
		if(olda[i].value==olda[i-1].value){//�������ֵԭֵ��ͬ������ֵ��ֵ��ͬ 
			newa[olda[i].id]=newa[olda[i-1].id];
		} 
	};
	
	for(int i=1;i<=n;i++)cout<<newa[i]<<" ";
	return 0;
	
}
