#include<iostream>
using namespace std;
const int N=1e6+5;
int heap[N],len=0;//��¼��ǰ�������ĳ���
void push(int x);
void pop();
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int op,x;
		cin>>op;
		if(op==1){
			cin>>x;
			push(x);
		}
		else if(op==2)printf("%d\n",heap[1]);
		else if(op==3)pop();
	};
	return 0;
};
//�ϸ� 
void push(int x){
	heap[++len]=x;
	int i=len;
	while(i>1&&heap[i]<heap[i/2]){//ע����ʼ��Ϊheap[1] 
		swap(heap[i],heap[i/2]);
		i=i/2;
	}
};
//�³�
void pop(){
	heap[1]=heap[len];
	heap[len]=0;
	--len;
	int i=1;
	while(2*i<=len){
		int son=2*i;//�����
		if(son<len&&heap[son+1]<heap[son])son++;//˵�����Ҷ��ӣ�ѡ��С�� 
	
		if(heap[i]>heap[son]){
			swap(heap[i],heap[son]);
			i=son;//�³������Ӵ� 
		}
		else break;//˵�����ȶ��Ӵ��� 
	}
} 



