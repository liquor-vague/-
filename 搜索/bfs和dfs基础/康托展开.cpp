//����չ����һά��������ά������м�¼����ʡ�ռ� 
#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
typedef long long ll;

int direction[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int visited[N]={0};
int start[9];//��ʼ״̬
int goal[9];//Ŀ��״̬ 
ll factory[]={1,1,2,6,24,120,720,5040,40320,362880};//9!


struct node{
	int state[9];//��¼�������״̬
	int dis;	//��¼�����ľ��� 
};
bool Cantor(int str[],int n){
	ll result=0;
	for(int i=0;i<n;i++){
		int rank=0;
		for(int j=i+1;j<n;j++){
			if(str[i]>str[j])++rank;//δ����Ԫ���ŵڼ��� 
		}
		result+=rank*factory[n-1-i];
	};
	if(!visited[result]){//δ������ 
		visited[result]=1;
		return 1;
	}
	else return 0;
} 
int bfs(){
	node head;
	memcpy(head.state,start,sizeof(head.state));//�������״̬ 
	head.dis=0;
	queue<node>q;
	Cantor(head.state,9);
	q.push(head);
	while(!q.empty()){//������� 
		head=q.front();
		//��Ŀ��״̬�Ƚ�
		if(memcmp(head.state,goal,sizeof(goal))==0)return head.dis;
		q.pop();
		
		int z;
		for(z=0;z<9;z++){//Ѱ��0��λ�� 
			if(head.state[z]==0)break;
		};
		//��0��λ��ת��Ϊ��ά���� 
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
				if(Cantor(newnode.state,9))q.push(newnode);//�������� 
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
