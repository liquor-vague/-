//�����¼�����0��ʼ����Ȼ���ӽڵ�Ū����� 
#include<iostream>
#include<algorithm>
using namespace std;
int arr[10005];
void max_heapify(int start,int end){
	int dad=start;
	int son=dad*2+1;
	while(son<=end) {
		if(son+1<=end&&arr[son]<arr[son+1])//ѡ��ϴ���ӽڵ�
			son++;
		if(arr[dad]>arr[son])//������ڵ�����ӽڵ�
			return;
		else { //���򽻻����ڵ���ӽڵ�
			swap(arr[dad],arr[son]);
			dad=son;
			son=dad*2+1;
		};
	}
};

void heap_sort(int len){
	//��ʼ���������һ�����ڵ㿪ʼ����
	for(int i=len/2-1;i>=0;i--)
	max_heapify(i,len-1);
	//����һ��Ԫ�غ��Ѿ��źõ�Ԫ��ǰһλ���������ٵ���
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
