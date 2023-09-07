//https://pintia.cn/problem-sets/15/exam/problems/821?type=7&page=0

//�����ĺ�ŵ������
//��ջģ��ݹ� 
#include<bits/stdc++.h>
using namespace std;

//���庺ŵ�����ƶ��ṹ
struct Move {
	int n;			//�ƶ�������
	char start;		//��ʼ����
	char middle;	//��������
	char target;	//Ŀ������
};

stack<Move>moves;
//��������ջģ��ݹ�
int Hanoi(int n,char start,char middle,char target) {
	
	int moveCount = 0;

	//��ʼ�����������⿴��һ���ƶ�����
	Move initial_Move = {n,start,middle,target};
	moves.push(initial_Move);
	while(!moves.empty()) {
		Move cur_Move = moves.top();
		moves.pop();

		n 	   = cur_Move.n;
		start  = cur_Move.start;
		middle = cur_Move.middle;
		target = cur_Move.target;

		if(n!=1) {
			//������ֽ�Ϊ���������⣬�����෴��˳�������
			Move move1 = {n-1,middle,start,target};		//���м������ӣ�����Ŀ�� 
			Move move2 = {1,start,middle,target};		//����С��������Ŀ�� 
			Move move3 = {n-1,start,target,middle};		//����ʼ�������������� 
			moves.push(move1);
			moves.push(move2);
			moves.push(move3);
		} else {
			//cout << "�ƶ����� " << " �� " << start << " �� " << target << endl;
			printf("%c -> %c\n",start,target);
			moveCount++;
		}
	};
	return moveCount;
}
int main() {
	int n;
	//cout<<"�����ƶ���������:";
	cin>>n;
	int myCount = Hanoi(n,'a','b','c');
	//cout << "���ƶ�������" << myCount << endl;
	return 0;
}
