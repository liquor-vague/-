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
	//������
	node*now,*p,*head,*pre;
	//�����һ���ڵ� 
	head=new node;
	head->data=1;
	head->next=NULL; 
	now=head;
	for(int i=2;i<=n;i++){
		p=new node;
		p->data=i;
		p->next=NULL;
		now->next=p;//���½ڵ�ӵ����� 
		now=p;//βָ����� 
	};
	now->next=head;//βָ��ָ��ͷ���պ� 
	//����
	now=head,pre=head; 
	while((n--)>1){
		for(int i=1;i<m;i++){
			pre=now;
			now=now->next;
		};
		printf("%d ",now->data);//�������ڵ㣬���ո� 
		pre->next=now->next;//��������ڵ�
		delete now;//�ͷ�����ڵ�
		now=pre->next; 
	};
	printf("%d",now->data);//��ӡ���һ���ڵ㣬�����ո� 
	delete now;
	return 0;
}
