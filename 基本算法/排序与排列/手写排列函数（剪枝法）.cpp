//2016À¶ÇÅ±­Ê¡aµÚÁùÌâ 
#include<iostream>
using namespace std;
int arr[20]={0,1,2,3,4,5,6,7,8,9,10,11,12,13};
int b[20],vis[20],ans=0;
void dfs(int s);

int main(){
	dfs(1);
	cout<<ans;
	return 0;
};

void dfs(int s){
	if(s==13){
		if(b[10]*b[11]==b[12])ans++;
		return;
	}
	if(s==4&&b[1]+b[2]!=b[3])return;
	if(s==7&&b[4]+b[5]!=b[6])return;
	if(s==10&&b[7]*b[8]!=b[9])return;
	for(int i=1;i<=13;i++){
		if(vis[i]==0){
			vis[i]=1;
			b[s]=arr[i];
			dfs(s+1);
			vis[i]=0; 
		}
	};
	
}
