#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int o[n];
	for(int i = 0 ; i < n ; i++){
		cin>>o[i];
	}
	int m;
	cin>>m;
	
	int ws = 0;
	int ans = -1;
	for(int we = 0 ; we < n; we++){
		m -= o[we];
		if( m < 0 ){
			m += o[ws];
			ws++;
		}
		else{
			ans = max( ans , we - ws + 1);
		}  
	}
	cout<<ans<<endl;
	return 0;
}
