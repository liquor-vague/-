//��άǰ׺��
#include<iostream>
using namespace std;
const int N=1005;
int d[N][N];
int main() {
	int n,m;
	cin>>n>>m;
	while(m--) {
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		d[x1][y1]++;//���
		d[x1][y2+1]--;//��x���ɳ�������y1��y2
		d[x2+1][y1]--;//��y���ɳ�������x1��x2
		d[x2+1][y2+1]++;//ǰ����������Σ����Բ���һ��

	};
	//�������ۼ�
	for(int i=1; i<=n; i++) {
		for(int j=1; j<n; j++) //�˴���j<n
			d[i][j+1]+=d[i][j];
	};
	//�������ۼ�
	for(int i=1; i<n; i++) { //�˴���i<n
		for(int j=1; j<=n; j++)
			d[i+1][j]+=d[i][j];
	};
	
	for(int i=1; i<=n; i++) { 
		for(int j=1; j<=n; j++)cout<<d[i][j]<<" ";
		cout<<endl;
		}
	return 0;
}
