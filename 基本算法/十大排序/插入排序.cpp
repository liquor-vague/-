#include<iostream>
using namespace std;
int arr[1005];
void insertion_sort(int n);

int main() {
	int n;
	cin>>n;//���������Ԫ�ظ���
	for(int i=1; i<=n; i++)cin>>arr[i]; //����ÿ��Ԫ��
	insertion_sort(n);
	for(int i=1; i<=n; i++)cout<<arr[i]<<"\t"; //���������Ԫ��
	return 0;
};

void insertion_sort(int n) {
	
	for(int i=2; i<=n; i++) {
		
		int key=arr[i];
		int j=i-1;
		
		while(j>0){
			
			if(key<arr[j]){
				arr[j+1]=arr[j];
				arr[j]=key;
			};
			
			j--;
		}
	};
}
