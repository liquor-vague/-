#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main(){
	string str;
	cin>>str;
	
	//��Ҫ�õ�ȫ���У���Ҫ����С������ 
	sort(str.begin(),str.end());
	
	cout<<str<<endl;
	//�������з�ΧΪ[first,last) 
	while(next_permutation(str.begin(),str.end())){
		cout<<str<<endl;
	};
	
	return 0;
} 
