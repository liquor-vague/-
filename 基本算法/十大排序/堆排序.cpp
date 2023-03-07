//数组记录必须从0开始，不然父子节点弄不清楚 
#include<iostream>
#include<algorithm>
using namespace std;
int arr[10005];
void max_heapify(int start,int end){
	int dad=start;
	int son=dad*2+1;
	while(son<=end) {
		if(son+1<=end&&arr[son]<arr[son+1])//选择较大的子节点
			son++;
		if(arr[dad]>arr[son])//如果父节点大于子节点
			return;
		else { //否则交换父节点和子节点
			swap(arr[dad],arr[son]);
			dad=son;
			son=dad*2+1;
		};
	}
};

void heap_sort(int len){
	//初始化，从最后一个父节点开始调整
	for(int i=len/2-1;i>=0;i--)
	max_heapify(i,len-1);
	//将第一个元素和已经排好的元素前一位做交换，再调整
	for(int i=len-1;i>0;i--){
		swap(arr[0],arr[i]);
		max_heapify(0,i-1);
	} 
	 
}
int main() {
	int len;
	cin>>len;
	for(int i=0;i<len;i++)cin>>arr[i];
	heap_sort(len);
	for(int i=0;i<len;i++)cout<<arr[i]<<' ';
	return 0;
}
