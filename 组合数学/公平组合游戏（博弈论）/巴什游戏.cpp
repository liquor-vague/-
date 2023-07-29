//luogu p4018
//╟мй╡сно╥ 
#include <bits/stdc++.h>
using namespace std;
const int N =1e5+5;
typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		if(n%6==0)cout<<"Roy wins!"<<endl;
		else cout<<"October wins!"<<endl;
	}
	
	return 0;
}

