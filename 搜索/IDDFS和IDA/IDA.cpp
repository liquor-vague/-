//IDA
//poj3134
#include<iostream>
#include<string.h>
using namespace std;
const int N=100;//最大层次
int num[N];//记录一条路径上的数字，num[i]是路径上第i层的数字 
int n,depth;
bool dfs(int now,int d){//now表示当前路径走到的数字，num[i]是路径上第i层数字 
	if(d>depth)return 0;
	if(now==n)return 1;
	if(now<<(depth-d)<n)return 0;//剪枝：剩下层数用最乐观的倍增法也不能达到n
	num[d]=now;//记录这条路径上第d层的数字
	for(int i=0;i<=d;i++){//遍历之前算过的数，继续下一层 
		if(dfs(now+num[i],d+1))return 1;//加
		else if(dfs(now-num[i],d+1))return 1;//减 
	} 
	return 0;
}
int main(){
	while(~scanf("%d",&n)&&n){
		for(depth=0;;depth++){//IDDFS：每次限制最大搜索depth层 
			memset(num,0,sizeof(num));
			if(dfs(1,0))break;//从数字1开始，当前层为0 
		};
		printf("%d\n",depth);
	};
	return 0;
}
