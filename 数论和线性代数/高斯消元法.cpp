//���p3389
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
	
	for(int i=1; i<=n; ++i) { //ö����
		int max=i;
		for(int j=i+1; j<=n; ++j) //ѡ��������ϵ������0��
			if(fabs(a[j][i])>fabs(a[max][i]))max=j;//��¼�������ϵ�������� 
		for(int j=1; j<=n+1; ++j)swap(a[i][j],a[max][j]); //�Ƶ�ǰ��
		if(fabs(a[i][i])<eps) {
			printf("No Solution");
			return 0;
		}
		for(int j=n+1; j>=1; j--)a[i][j]=a[i][j]/a[i][i];
		//����һ�е���Ԫϵ����Ϊ1
		for(int j=1; j<=n;++j) {
			if(j!=i) {//������Ԫ���ڵ����� 
				double temp=a[j][i]/a[i][i];//���Ե�ǰ��һ�е���Ԫ��  
				for(int k=1;k<=n+1;k++)a[j][k]-=a[i][k]*temp;//���м�ȥ��Ԫ�������б��� 
			}
		}
	};
	for(int i=1;i<=n;++i)printf("%.2f\n",a[i][n+1]);
	return 0;
}
