//hdu1062
//将输入的字符倒序输出 

#include<cstdio>
#define max 10005
using namespace std;
struct stack {
	char arr[max];			//存入栈的元素

	int t=0;				//栈顶

	void push(char x) {
		arr[++t]=x;			//压入栈
	};

	char top() {
		return arr[t];		//回到栈顶
	};		

	void pop() {			//弹出栈 
		t--;
	};
	
	int empty(){			//查看栈是否为空 
		return t==0?1:0;
	}

}st;
int main() {
	int n;
	scanf("%d",&n);
	while(n--){
		while(true){
			char ch=getchar();
			if(ch==' '||ch=='\n'){//检测到空格或换行 
				while(st.empty()!=1){
					printf("%c",st.top());//输出栈顶数据 
					st.pop();//弹出栈顶 
				};
				
			if(ch=='\n')break;//检测到换行键就结束这行循环 
			printf(" ");		//否则打印空格 
			
			}
			
			else(st.push(ch));//否则存入栈内 
			 
		};
		printf("\n");
	};
	return 0;
}
