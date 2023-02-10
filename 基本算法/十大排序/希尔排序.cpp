//希尔排序属于插入类排序,是将整个有序序列分割成若干小的子序列分别进行插入排序。


#include<iostream>
using namespace std;
int arr[1005];
void Shell_Sort(int n);

int main() {
	int n;
	cin>>n;//输入排序的元素个数
	for(int i=1; i<=n; i++)cin>>arr[i]; //输入每个元素
	Shell_Sort(n);
	for(int i=1; i<=n; i++)cout<<arr[i]<<"\t"; //输出排序后的元素
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

