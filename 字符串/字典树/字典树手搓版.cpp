//luoguP2580
//�ֵ�����ֻ��26��Сд��ĸ
//���һ�����Ե㲻�� 
#include<bits/stdc++.h>
using namespace std;
const int N = 8e5;
struct node {
	bool repeat;	//���ǰ׺�Ƿ��ظ�
	int son[26];	//26����ĸ
	int num;		//�ֵ���
} t[N];
int cnt = 1;		//��ǰ�·���Ĵ洢λ�ã�cnt=0�Ǹ��ڵ�

void insert(char*s) {
	int now = 0;
	int len = strlen(s); 
	for(int i=0; i<len; i++) {
		int ch = s[i]-'a';
		if(t[now].son[ch] == 0)				//�������ַ���û�д洢��
			t[now].son[ch] = cnt++;			//��cntλ�÷��������ַ�
		now = t[now].son[ch];
		t[now].num++;
	}
}

int find(char*s) {
	int now = 0;
	int len = strlen(s); 
	for(int i=0; i<len; i++) {
		int ch = s[i]-'a';
		if(t[now].son[ch] == 0)return 3;	//��1���ַ����Ҳ���
		now = t[now].son[ch];
	};
	if(t[now].num == 0)return 3;			//���ǰ׺û�г��ֹ�
	if(t[now].repeat == false) {				//��һ�α�����
		t[now].repeat = true;
		return 1;
	};
	return 2;
	//return t[p].num;						//�������Ҫ��������sΪǰ׺�ĵ�������
};


int main() {
	char s[55];
	int n;
	cin>>n;
	while(n--) {
		cin>>s;
		insert(s);
	}
	int m;
	cin>>m;
	while(m--) {
		cin>>s;
		int r = find(s);
		if(r == 1)cout<<"OK\n";
		if(r == 2)cout<<"REPEAT\n";
		if(r == 3) cout<<"WRONG\n";
	};
	return 0;
}
