//用STL写的最小堆 
#include<iostream>
#include<queue>
using namespace std;
int ans[1000005];
int main(){
	priority_queue<int,vector<int>,greater<int> >q;
	//优先级队列的模板：priority_queue<Type, Container, Functional>
	//Type是数据类型，Container是容器,Functional是比较方式 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int op,x;
		cin>>op;
		if(op==1){
			cin>>x;
			q.push(x);
		}
		else if(op==2)ans[i]=q.top();
		else if(op==3)q.pop();
	};
	for(int i=1;i<=n;i++)if(ans[i]!=0)cout<<ans[i]<<endl;
	return 0;
} 
