#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	
	int dp[n+1][k+1];
	memset(dp,0,sizeof(dp));
	
	dp[0][0] = 1; //no. of ways to group 0 people for 0 computers.

	for(int i = 1 ; i <= n ; i++){ // iterate for every person. <= for n persons 
		for(int j = 1; j <= min(i,k) ; j++){ //we cannot allocate x no. of computers to <x people 
			dp[i][j] = dp[i-j][j] + dp[i-1][j-1];
		}
	}
	
	cout<<dp[n][k]<<endl;
}
