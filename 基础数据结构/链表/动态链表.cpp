#include<cstdio>
#include<cstdlib>
using namespace std;
struct node{
	int data;
	node*next;
};
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	//存人数
	node*now,*p,*head,*pre;
	//分配第一个节点 
	head=new node;
	head->data=1;
	head->next=NULL; 
	now=head;
	for(int i=2;i<=n;i++){
		p=new node;
		p->data=i;
		p->next=NULL;
		now->next=p;//将新节点接到链表 
		now=p;//尾指针后移 
	};
	now->next=head;//尾指针指向头，闭合 
	//报数
	now=head,pre=head; 
	while((n--)>1){
		for(int i=1;i<m;i++){
			pre=now;
			now=now->next;
		};
		printf("%d ",now->data);//输出这个节点，带空格 
		pre->next=now->next;//跳过这个节点
		delete now;//释放这个节点
		now=pre->next; 
	};
	printf("%d",now->data);//打印最后一个节点，不带空格 
	delete now;
	return 0;
}
