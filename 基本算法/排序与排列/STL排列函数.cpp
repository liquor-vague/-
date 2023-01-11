#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main(){
	string str;
	cin>>str;
	
	//若要得到全排列，则要从最小的排起 
	sort(str.begin(),str.end());
	
	cout<<str<<endl;
	//函数排列范围为[first,last) 
	while(next_permutation(str.begin(),str.end())){
		cout<<str<<endl;
	};
	
	return 0;
} 
