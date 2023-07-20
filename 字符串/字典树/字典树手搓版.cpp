//luoguP2580
//字典树，只有26个小写字母
//最后一个测试点不过 
#include<bits/stdc++.h>
using namespace std;
const int N = 8e5;
struct node {
	bool repeat;	//检查前缀是否重复
	int son[26];	//26个字母
	int num;		//字典树
} t[N];
int cnt = 1;		//当前新分配的存储位置，cnt=0是根节点

void insert(char*s) {
	int now = 0;
	int len = strlen(s); 
	for(int i=0; i<len; i++) {
		int ch = s[i]-'a';
		if(t[now].son[ch] == 0)				//如果这个字符还没有存储过
			t[now].son[ch] = cnt++;			//把cnt位置分配给这个字符
		now = t[now].son[ch];
		t[now].num++;
	}
}

int find(char*s) {
	int now = 0;
	int len = strlen(s); 
	for(int i=0; i<len; i++) {
		int ch = s[i]-'a';
		if(t[now].son[ch] == 0)return 3;	//第1个字符就找不到
		now = t[now].son[ch];
	};
	if(t[now].num == 0)return 3;			//这个前缀没有出现过
	if(t[now].repeat == false) {				//第一次被点名
		t[now].repeat = true;
		return 1;
	};
	return 2;
	//return t[p].num;						//如果有需要，返回以s为前缀的单词数量
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
