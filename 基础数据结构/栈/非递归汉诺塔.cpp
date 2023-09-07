//https://pintia.cn/problem-sets/15/exam/problems/821?type=7&page=0

//迭代的汉诺塔问题
//用栈模拟递归 
#include<bits/stdc++.h>
using namespace std;

//定义汉诺塔的移动结构
struct Move {
	int n;			//移动盘子数
	char start;		//起始柱子
	char middle;	//辅助柱子
	char target;	//目标柱子
};

stack<Move>moves;
//迭代，用栈模拟递归
int Hanoi(int n,char start,char middle,char target) {
	
	int moveCount = 0;

	//初始化将整个问题看作一个移动操作
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
			//将问题分解为三个子问题，按照相反的顺序推入堆
			Move move1 = {n-1,middle,start,target};		//若中间有盘子，移向目标 
			Move move2 = {1,start,middle,target};		//将最小盘子移向目标 
			Move move3 = {n-1,start,target,middle};		//将起始盘子移向辅助柱子 
			moves.push(move1);
			moves.push(move2);
			moves.push(move3);
		} else {
			//cout << "移动盘子 " << " 从 " << start << " 到 " << target << endl;
			printf("%c -> %c\n",start,target);
			moveCount++;
		}
	};
	return moveCount;
}
int main() {
	int n;
	//cout<<"输入移动的盘子数:";
	cin>>n;
	int myCount = Hanoi(n,'a','b','c');
	//cout << "总移动次数：" << myCount << endl;
	return 0;
}
