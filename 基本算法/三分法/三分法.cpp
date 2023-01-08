#include<cstdio>
using namespace std;
int n;
double arr[15];
double function(double x); 
int main(){
	double left,right;
	scanf("%d%lf%lf",&n,&left,&right);
	
	for(int i=n;i>=0;i--)scanf("%lf",&arr[i]);
	
	while((right-left)>1e-6){
		double k=(right-left)/3.0;
		double mid1,mid2;
		mid1=left+k;
		mid2=right-k;
		if(function(mid1)>function(mid2))right=mid2;
		else left=mid1;
		
	}
	
	printf("%.6f",left);
	return 0;
	
};
double function(double x){//º¯ÊıÖµ
	double sum=0;
	for(int i=n;i>=0;i--)sum=sum*x+arr[i];
	return sum;
}
