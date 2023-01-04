//p1540
//队列
#include<iostream>
#define max 1005 //队列大小 
using namespace std;
int Hash[max]= {0};//标志数组 
struct queue {
	int data[max];
	int head,tail;
	//初始化
	void initialization() {
		head=tail=0;
	};

	//压入
	void push(int x) {
		data[tail]=x;
		tail=(tail+1)%max;
	
	};
	//弹出
	void pop() {
		if(head==tail)return;//队列空
		int tmp=data[head];
		Hash[tmp]=0;		//查找清零 
		head=head+1;
	};
	//回到队头
	int front() {
		return data[head];
	};
	//队列长度
	int size() {
		return (tail-head+max)%max;
	};
} q;

int main() {
	q.initialization();
	int m,n;
	cin>>m>>n;
	int calls=0;
	while(n--) {
		int word;
		cin>>word;
		if(Hash[word]==0) { //尚未存入
			++calls;
			q.push(word);
			Hash[word]=1;
			while(q.size()>m) {//队列已满
				q.pop();
			};
		};
	};
	cout<<calls;
	return 0;
}
