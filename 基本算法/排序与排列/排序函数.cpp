//洛谷p1093
//调用库函数中的排序函数
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int sum[305];
struct student {
	int number;
	int chinese;
	int math;
	int english;
} stu[305];
void swap(int n);

int main() {
	int n;
	cin>>n;

	for(int i=1; i<=n; i++) {
		stu[i].number=i;
		cin>>stu[i].chinese>>stu[i].math>>stu[i].english;
		sum[i]=stu[i].chinese+stu[i].math+stu[i].english;
	};
	
	swap(n);
	for(int i=1; i<6; i++)printf("%d %d\n",stu[i].number,sum[i]);
	
	return 0;
};

void swap(int n) {
	int temp;
	for(int j=1; j<n; j++) {
		for(int i=1; i<n; i++) {
			if(sum[i]==sum[i+1]) { //总分相同时
				//比较语文成绩
				if(stu[i].chinese<stu[i+1].chinese) {
					temp=stu[i+1].number;
					stu[i+1].number=stu[i].number;
					stu[i].number=temp;

					temp=stu[i+1].chinese;
					stu[i+1].chinese=stu[i].chinese;
					stu[i].chinese=temp;
				}
				//语文成绩相同时
				else if((stu[i].chinese==stu[i+1].chinese)&&stu[i].number>stu[i+1].number) {
					temp=stu[i+1].number;
					stu[i+1].number=stu[i].number;
					stu[i].number=temp;


				}

			}

			else if(sum[i]<sum[i+1]) {
				temp=sum[i+1];
				sum[i+1]=sum[i];
				sum[i]=temp;

				temp=stu[i+1].number;
				stu[i+1].number=stu[i].number;
				stu[i].number=temp;

				temp=stu[i+1].chinese;
				stu[i+1].chinese=stu[i].chinese;
				stu[i].chinese=temp;

			}

		}
	}
}
