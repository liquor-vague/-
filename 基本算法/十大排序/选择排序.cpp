#include<iostream>
using namespace std;
int arr[1005];
void selection_sort(int n);

int main() {
	int n;
	cin>>n;//���������Ԫ�ظ���
	for(int i=1; i<=n; i++)cin>>arr[i]; //����ÿ��Ԫ��
	selection_sort(n);
	for(int i=1; i<=n; i++)cout<<arr[i]<<"\t"; //���������Ԫ��
	return 0;
};

void selection_sort(int n) {
	int temp,min_i;
	for(int i=1; i<=n; i++) {

		temp=arr[i],min_i=i;

		for(int j=i; j<=n; j++) {
			if(arr[j]<temp) {
				min_i=j;
				temp=arr[j];
			}
		};

		temp=arr[i];
		arr[i]=arr[min_i];
		arr[min_i]=temp;

	}
}
