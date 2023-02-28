//康托展开用一维数组代替二维数组进行记录，节省空间 
#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
typedef long long ll;

int direction[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int visited[N]={0};
int start[9];//开始状态
int goal[9];//目标状态 
ll factory[]={1,1,2,6,24,120,720,5040,40320,362880};//9!


struct node{
	int state[9];//记录八数码的状态
	int dis;	//记录到起点的距离 
};
bool Cantor(int str[],int n){
	ll result=0;
	for(int i=0;i<n;i++){
		int rank=0;
		for(int j=i+1;j<n;j++){
			if(str[i]>str[j])++rank;//未出现元素排第几个 
		}
		result+=rank*factory[n-1-i];
	};
	if(!visited[result]){//未被访问 
		visited[result]=1;
		return 1;
	}
	else return 0;
} 
int bfs(){
	node head;
	memcpy(head.state,start,sizeof(head.state));//复制起点状态 
	head.dis=0;
	queue<node>q;
	Cantor(head.state,9);
	q.push(head);
	while(!q.empty()){//处理队列 
		head=q.front();
		//与目标状态比较
		if(memcmp(head.state,goal,sizeof(goal))==0)return head.dis;
		q.pop();
		
		int z;
		for(z=0;z<9;z++){//寻找0的位置 
			if(head.state[z]==0)break;
		};
		//将0的位置转换为二维坐标 
		int x=z%3;
		int y=z/3;
		for(int i=0;i<4;i++){
			int nx=x+direction[i][0],ny=y+direction[i][1];
			int nz=nx+ny*3;
			if(nx>=0&&ny>=0&&nx<3&&ny<3){
				node newnode;
				memcpy(&newnode,&head,sizeof(node));
				swap(newnode.state[z],newnode.state[nz]);
				newnode.dis++;
				if(Cantor(newnode.state,9))q.push(newnode);//康托判重 
			}
		}
	};
	return -1;
}
int main(){
	for(int i=0;i<9;i++)cin>>start[i];
	for(int i=0;i<9;i++)cin>>goal[i];
	int ans=bfs();
	if(ans!=-1)cout<<ans;
	else cout<<"Impossible";
	return 0;
} 
