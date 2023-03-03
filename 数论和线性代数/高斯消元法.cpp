//洛谷p3389
#include<iostream>
#include<cmath>
using namespace std;
double a[105][105];
double eps=1e-7;
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n+1;++j)scanf("%lf",&a[i][j]);
	};
	
	for(int i=1; i<=n; ++i) { //枚举列
		int max=i;
		for(int j=i+1; j<=n; ++j) //选择该列最大系数（非0）
			if(fabs(a[j][i])>fabs(a[max][i]))max=j;//记录该列最大系数的行数 
		for(int j=1; j<=n+1; ++j)swap(a[i][j],a[max][j]); //移到前面
		if(fabs(a[i][i])<eps) {
			printf("No Solution");
			return 0;
		}
		for(int j=n+1; j>=1; j--)a[i][j]=a[i][j]/a[i][i];
		//把这一行的主元系数变为1
		for(int j=1; j<=n;++j) {
			if(j!=i) {//不消主元所在的行数 
				double temp=a[j][i]/a[i][i];//除以当前这一列的主元列  
				for(int k=1;k<=n+1;k++)a[j][k]-=a[i][k]*temp;//该行减去主元列所在行倍数 
			}
		}
	};
	for(int i=1;i<=n;++i)printf("%.2f\n",a[i][n+1]);
	return 0;
}
