//hdu1062
//��������ַ�������� 

#include<cstdio>
#define max 10005
using namespace std;
struct stack {
	char arr[max];			//����ջ��Ԫ��

	int t=0;				//ջ��

	void push(char x) {
		arr[++t]=x;			//ѹ��ջ
	};

	char top() {
		return arr[t];		//�ص�ջ��
	};		

	void pop() {			//����ջ 
		t--;
	};
	
	int empty(){			//�鿴ջ�Ƿ�Ϊ�� 
		return t==0?1:0;
	}

}st;
int main() {
	int n;
	scanf("%d",&n);
	while(n--){
		while(true){
			char ch=getchar();
			if(ch==' '||ch=='\n'){//��⵽�ո���� 
				while(st.empty()!=1){
					printf("%c",st.top());//���ջ������ 
					st.pop();//����ջ�� 
				};
				
			if(ch=='\n')break;//��⵽���м��ͽ�������ѭ�� 
			printf(" ");		//�����ӡ�ո� 
			
			}
			
			else(st.push(ch));//�������ջ�� 
			 
		};
		printf("\n");
	};
	return 0;
}
