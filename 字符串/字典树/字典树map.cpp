//luoguP2580
//map
#include<bits/stdc++.h>
using namespace std;
int main(){
	map<string,int>student;
	int n,m;
	string name;
	cin>>n;
	while(n--){
		cin>>name;
		student[name]=1;
	};
	cin>>m;
	while(m--){
		cin>>name;
		if(student[name]==1){
			cout<<"OK\n";
			student[name]=2;
		}
		else if(student[name]==2)cout<<"REPEAT\n";
		else cout<<"WRONG\n";
	}
	return 0;
}
