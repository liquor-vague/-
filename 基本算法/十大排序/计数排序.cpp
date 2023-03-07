//��������Է�Χ��С��������Ч�����ڷ�Χ������ݿռ临�Ӷ�̫��
//����������ݷ�Χ��0-100��������������ɣ�ֻ���������ݸ��� 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void print_arr(int*arr,int n) {
	for(int i=0; i<n; i++)printf("%d ",arr[i]);
	printf("\n");
};
void counting_sort(int*init_arr,int*sorted_arr,int n) {
	int*count_arr=(int*)malloc(sizeof(int)*100);
	//��ʼ��
	for (int k=0;k<100;k++)
		count_arr[k]=0;
	//��һ�����ֳ��ֵĴ���
	for(int i=0; i<n; i++)
		count_arr[init_arr[i]]++;
	//��ǰ׺��
	for(int k=1; k<100; k++)
		count_arr[k]+=count_arr[k - 1];
	//����ǰ׺�ʹ浽��Ӧ��λ�� 
	for(int j=n; j>0; j--)
		sorted_arr[--count_arr[init_arr[j-1]]]=init_arr[j-1];
}
int main(int argc,char**argv) {
	int len;//���������ݸ���
	scanf("%d",&len);
	int*arr=(int*)malloc(sizeof(int)*len);
	int*sorted_arr=(int*)malloc(sizeof(int)*len);
	srand(time(0));
	for(int i=0; i<len; i++)arr[i]=rand()%100;
	printf("init_array:");
	print_arr(arr,len);
	counting_sort(arr,sorted_arr,len);
	printf("sorted_array:");
	print_arr(sorted_arr,len);
	free(arr);
	free(sorted_arr);
	return 0;
}
