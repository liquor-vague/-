#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int a[N];
int n;
int paritition(int l,int r);
void quick_sort(int l,int r);
int main() {
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i];
	quick_sort(1,n);
	for(int i=1; i<=n; i++)cout<<a[i];
	return 0;
};
void quick_sort(int l,int r) {
	if(l<r) {
		int pivot=paritition(l,r);//����
		quick_sort(l,pivot-1);
		quick_sort(pivot+1,r); 

	}
};

int paritition(int l,int r) {
	int pivot=a[l];
	while(l<r) {
		while (l<r && a[r] >= pivot)--r;
		a[l]=a[r];//����ε�һ��С��pivot�Ľ��� 
		while (l<r && a[l] <= pivot)++l;
		a[r]=a[l];//��ǰ��ε�һ������pivot�Ľ��� 
	};
	a[l]=pivot;
	return l;
}
