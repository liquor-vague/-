//��������STL����
//���p3369
//lower_bound��begin()����ֵ����ָ�� 
#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main(){
	int n,opt,x;
	cin>>n;
	while(n--){
		cin>>opt>>x;
		if(opt==1)v.insert(lower_bound(v.begin(),v.end(),x),x);
		if(opt==2)v.erase(lower_bound(v.begin(),v.end(),x));
		if(opt==3)cout<<lower_bound(v.begin(),v.end(),x)-v.begin()+1<<endl; 
		if(opt==4)cout<<v[x-1]<<endl;
		if(opt==5)cout<<v[lower_bound(v.begin(),v.end(),x)-v.begin()-1]<<endl;
		if(opt==6)cout<<v[upper_bound(v.begin(),v.end(),x)-v.begin()]<<endl;
	};
	return 0;
}
