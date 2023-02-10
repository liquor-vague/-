#include<iostream>
using namespace std;
int arr[1005];
void bubble_sort(int n);

int main() {
	int n;
	cin>>n;//输入排序的元素个数
	for(int i=1; i<=n; i++)cin>>arr[i]; //输入每个元素
	bubble_sort(n);
	for(int i=1; i<=n; i++)cout<<arr[i]<<"\t"; //输出排序后的元素
	return 0;
};

void bubble_sort(int n){
	int temp;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
