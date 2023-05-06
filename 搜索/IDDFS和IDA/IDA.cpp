//IDA
//poj3134
#include<iostream>
#include<string.h>
using namespace std;
const int N=100;//�����
int num[N];//��¼һ��·���ϵ����֣�num[i]��·���ϵ�i������� 
int n,depth;
bool dfs(int now,int d){//now��ʾ��ǰ·���ߵ������֣�num[i]��·���ϵ�i������ 
	if(d>depth)return 0;
	if(now==n)return 1;
	if(now<<(depth-d)<n)return 0;//��֦��ʣ�²��������ֹ۵ı�����Ҳ���ܴﵽn
	num[d]=now;//��¼����·���ϵ�d�������
	for(int i=0;i<=d;i++){//����֮ǰ���������������һ�� 
		if(dfs(now+num[i],d+1))return 1;//��
		else if(dfs(now-num[i],d+1))return 1;//�� 
	} 
	return 0;
}
int main(){
	while(~scanf("%d",&n)&&n){
		for(depth=0;;depth++){//IDDFS��ÿ�������������depth�� 
			memset(num,0,sizeof(num));
			if(dfs(1,0))break;//������1��ʼ����ǰ��Ϊ0 
		};
		printf("%d\n",depth);
	};
	return 0;
}
