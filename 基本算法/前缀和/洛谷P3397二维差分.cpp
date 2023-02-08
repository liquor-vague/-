//二维前缀和
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
		d[x1][y1]++;//起点
		d[x1][y2+1]--;//把x看成常数，从y1到y2
		d[x2+1][y1]--;//把y看成常数，从x1到x2
		d[x2+1][y2+1]++;//前面减少了两次，所以补回一次

	};
	//纵坐标累加
	for(int i=1; i<=n; i++) {
		for(int j=1; j<n; j++) //此处是j<n
			d[i][j+1]+=d[i][j];
	};
	//横坐标累加
	for(int i=1; i<n; i++) { //此处是i<n
		for(int j=1; j<=n; j++)
			d[i+1][j]+=d[i][j];
	};
	
	for(int i=1; i<=n; i++) { 
		for(int j=1; j<=n; j++)cout<<d[i][j]<<" ";
		cout<<endl;
		}
	return 0;
}
