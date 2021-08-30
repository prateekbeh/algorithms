#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s,t;
	cin>>s>>t;
	
	int n = t.length();
	int m = s.length();
	int dp[m+1][n+1];
	memset(dp,0,sizeof(dp));
	
	for(int i = 0 ; i <= m ; i++){
		dp[0][i] = 1;
	}

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i-1]==t[j-1]) 
				dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			else
				dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[m][n]<<endl;
	
}
