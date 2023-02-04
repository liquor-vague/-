#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int> >q;
	string str;
	while (getline(cin, str) && str != "END") {
		sort(str.begin(), str.end());

		//计算一种字符出现的次数
		int num = 1;
		for (int i = 1; i <= str.length(); i++) {
			if (str[i] != str[i - 1]) {
				q.push(num);
				num = 1;
			} else num++;
		}

		int ans = 0;
		//如果只有一种字符
		if (q.size() == 1)ans = str.length();

		while (q.size() > 1) {
			//最后一次合并不加入ans
			//贪心，先取出出现频率最低的两个
			int a = q.top();
			q.pop();
			int b = q.top();
			q.pop();
			//合并节点
			q.push(a + b);
			ans += a + b;

		};
		q.pop();
		printf("%d %d ", str.length() * 8, ans);
		printf("%.1f\n", (double)str.length() * 8 / ans);
	};
	return 0;
}
