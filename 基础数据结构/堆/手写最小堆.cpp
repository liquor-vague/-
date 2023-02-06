#include<iostream>
using namespace std;
const int N=1e6+5;
int heap[N],len=0;//记录当前二叉树的长度
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
//上浮 
void push(int x){
	heap[++len]=x;
	int i=len;
	while(i>1&&heap[i]<heap[i/2]){//注意起始点为heap[1] 
		swap(heap[i],heap[i/2]);
		i=i/2;
	}
};
//下沉
void pop(){
	heap[1]=heap[len];
	heap[len]=0;
	--len;
	int i=1;
	while(2*i<=len){
		int son=2*i;//左儿子
		if(son<len&&heap[son+1]<heap[son])son++;//说明有右儿子，选最小的 
	
		if(heap[i]>heap[son]){
			swap(heap[i],heap[son]);
			i=son;//下沉到儿子处 
		}
		else break;//说明不比儿子大了 
	}
} 



