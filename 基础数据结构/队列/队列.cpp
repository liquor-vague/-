//p1540
//����
#include<iostream>
#define max 1005 //���д�С 
using namespace std;
int Hash[max]= {0};//��־���� 
struct queue {
	int data[max];
	int head,tail;
	//��ʼ��
	void initialization() {
		head=tail=0;
	};

	//ѹ��
	void push(int x) {
		data[tail]=x;
		tail=(tail+1)%max;
	
	};
	//����
	void pop() {
		if(head==tail)return;//���п�
		int tmp=data[head];
		Hash[tmp]=0;		//�������� 
		head=head+1;
	};
	//�ص���ͷ
	int front() {
		return data[head];
	};
	//���г���
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
		if(Hash[word]==0) { //��δ����
			++calls;
			q.push(word);
			Hash[word]=1;
			while(q.size()>m) {//��������
				q.pop();
			};
		};
	};
	cout<<calls;
	return 0;
}
