#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int iv[n],articles[n];
	fill_n(iv,n,0);
	fill_n(articles,n,0);
	
	for(int i = 0 ; i < n ; i++){
		cin>>iv[i];
	}
	cin>>n;
	
	for(int i = 0 ; i < n ; i++){
		cin>>articles[i];
		articles[i] = articles[i] * 2;
	}
	
	int p;
	cin>>p;
	
	int dp[n+1][p+1];
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= p ; j++){
			dp[i][j] = 0;
		}
	}

	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= p ; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
				continue;
			}
			if(articles[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = max(iv[i-1] + dp[i-1][j - articles[i-1]], dp[i-1][j]);
			}
		}
	}
	cout<<dp[n][p]<<endl;
	return 0;
}
