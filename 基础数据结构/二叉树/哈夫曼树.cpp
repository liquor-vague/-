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

		//����һ���ַ����ֵĴ���
		int num = 1;
		for (int i = 1; i <= str.length(); i++) {
			if (str[i] != str[i - 1]) {
				q.push(num);
				num = 1;
			} else num++;
		}

		int ans = 0;
		//���ֻ��һ���ַ�
		if (q.size() == 1)ans = str.length();

		while (q.size() > 1) {
			//���һ�κϲ�������ans
			//̰�ģ���ȡ������Ƶ����͵�����
			int a = q.top();
			q.pop();
			int b = q.top();
			q.pop();
			//�ϲ��ڵ�
			q.push(a + b);
			ans += a + b;

		};
		q.pop();
		printf("%d %d ", str.length() * 8, ans);
		printf("%.1f\n", (double)str.length() * 8 / ans);
	};
	return 0;
}
