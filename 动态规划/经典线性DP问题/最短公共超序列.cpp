#include<iostream>
#include<string.h>
using namespace std;
const int N=1005;
char str1[N],str2[N],ans[N];//ans������Ź���������
int len1,len2,count;
int dp[N][N];
int main(){
	int i,j;
	
	cin>>str1>>str2;
	len1=strlen(str1),len2=strlen(str2);
	
	//�������һλ�� �����������
	for(i=len1;i>0;i--)str1[i]=str1[i-1]; 
	for(i=len2;i>0;i--)str2[i]=str2[i-1];
	
	//���������긳��ֵ
	for(i=0;i<=max(len1,len2);i++)dp[i][0]=dp[0][i]=i;
	
	//���㹫�������е�λ��
	for(i=1;i<=len1;i++){
		for(j=1;j<=len2;j++){
			//����ĸ�Ѿ��ڹ����������� 
			if(str1[i]==str2[j])dp[i][j]=dp[i-1][j-1]+1;
			////����ĸ���ڹ����������� 
			else dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
		}
	};
	
	i=len1,j=len2;
	count=0;
	
	//���㹫��������
	while(i>0&&j>0){
		//����ͬ 
		if(dp[i][j]==dp[i-1][j-1]+1&&str1[i]==str2[j]){
			ans[count]=str1[i];
			count++;
			i--;
			j--;
		}
		//������str1
		else if(dp[i][j]==dp[i-1][j]+1&&str1[i]!=str2[j]){
			ans[count]=str1[i];
			count++;
			i--;
		}
		//������str2
		else if(dp[i][j]==dp[i][j-1]+1&&str1[i]!=str2[j]){
			ans[count]=str2[j];
			count++;
			j--;
		}
	};
	//ʣ�µ�
	while(i>0){
		ans[count]=str1[i];
		count++;
		i--;
	};
	while(j>0){
		ans[count]=str2[j];
		count++;
		j--;
	};
	
	//������
	for(i=count-1;i>=0;i--)cout<<ans[i];
	cout<<endl;
    //cout<<dp[len1][len2]
	return 0; 
} 
