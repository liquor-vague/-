//运用了STL
//书图3.1 
#include<queue>
#include<iostream>
using namespace std;
const int n=1005;
struct node {
	char value;
	int lson,rson;//左节点和右节点
}tree[n];
//记录节点存在tree的位置，从tree[1]开始，tree[0]为空节点
int index=1;

int newnode(char val) {
	tree[index].value=val;
	tree[index].lson=0;
	tree[index].rson=0;
	return index++;
};

void insert(int&father,int child,int l_r) { //插入孩子
	if(l_r==0)tree[father].lson=child;
	else tree[father].rson=child;
}

int build_tree(){
	int A=newnode('A'),B=newnode('B'),C=newnode('C');
	int D=newnode('D'),E=newnode('E'),F=newnode('F');
	int G=newnode('G'),H=newnode('H'),I=newnode('I');
	//E的左右孩子 
	insert(E,B,0);
	insert(E,G,1);
	//B的左右孩子
	insert(B,A,0); 
	insert(B,D,1);
	//D的左孩子
	insert(D,C,0);
	//G的左右孩子
	insert(G,F,0);
	insert(G,I,1);
	//I的左孩子
	insert(I,H,0);
	
	int root=E;
	return root;
};

int main(){
	int root=build_tree();
	queue<int>q;
	q.push(root);
	while(q.size()){
		int temp=q.front();
		cout<<tree[temp].value<<" ";//打印队头
		q.pop();
		if(tree[temp].lson!=0)q.push(tree[temp].lson);
		if(tree[temp].rson!=0)q.push(tree[temp].rson);
	}
	return 0;
}
