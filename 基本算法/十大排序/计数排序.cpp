//计数排序对范围较小的数据有效，对于范围大的数据空间复杂度太高
//这里假设数据范围在0-100，采用随机数生成，只需输入数据个数 
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
	//初始化
	for (int k=0;k<100;k++)
		count_arr[k]=0;
	//求一个数字出现的次数
	for(int i=0; i<n; i++)
		count_arr[init_arr[i]]++;
	//求前缀和
	for(int k=1; k<100; k++)
		count_arr[k]+=count_arr[k - 1];
	//根据前缀和存到相应的位置 
	for(int j=n; j>0; j--)
		sorted_arr[--count_arr[init_arr[j-1]]]=init_arr[j-1];
}
int main(int argc,char**argv) {
	int len;//数组中数据个数
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
