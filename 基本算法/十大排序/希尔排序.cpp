//ϣ���������ڲ���������,�ǽ������������зָ������С�������зֱ���в�������


#include<iostream>
using namespace std;
int arr[1005];
void Shell_Sort(int n);

int main() {
	int n;
	cin>>n;//���������Ԫ�ظ���
	for(int i=1; i<=n; i++)cin>>arr[i]; //����ÿ��Ԫ��
	Shell_Sort(n);
	for(int i=1; i<=n; i++)cout<<arr[i]<<"\t"; //���������Ԫ��
	return 0;
};

void Shell_Sort(int n) {

	int gap=n;

	while(gap!=1) {
		gap=gap/2;

		for(int i=1; i<=gap; i++) {
			
			for(int j=i+gap; j<=n; j=j+gap) {

				int temp=arr[j];
				int k;
				for(k=j-gap; k>=0&&arr[k]>temp; k=k-gap) {

					arr[k+gap]=arr[k];

				}
				arr[k+gap]=temp;
			}
		}
	}
}

