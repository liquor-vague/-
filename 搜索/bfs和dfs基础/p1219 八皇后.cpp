#include<iostream>
using namespace std;
const int N=100;
int a[N],b[N],c[N],d[N];//�У��У����Խ��ߣ����Խ���
int n;
int sum;
void print() {
	if(sum<3) {
		for(int k=1; k<=n; k++)cout<<a[k]<<" ";
		cout<<endl;
	}
	sum++;
}
void queen(int x) {
	if(x>n) {
		print();
		return;
	}

	else {
		for(int y=1; y<=n; y++) {
			if((!b[y])&&(!c[y-x+n])&&(!d[x+y])) {
				a[x]=y;
				b[y]=1;
				//���Խ�����(y-x)��ͬ
				c[y-x+n]=1;
				//���Խ�����(x+y)��ͬ
				d[x+y]=1;
				//��һ���ʺ�
				queen(x+1);
				//����
				b[y]=0;
				c[y-x+n]=0;
				d[x+y]=0;
			}
		}
	}
};

int main() {
	cin>>n;
	queen(1);
	cout<<sum;
	return 0;
};

