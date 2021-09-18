#include<bits/stdc++.h>

using namespace std;

#define INF 123456789

int main()
{
	int t;
	cin>>t;

	while(t--){
		int n,m;
		cin>>n>>m;
		assert( n <= 1000 && m <= 1000);
		int arr[n+1][m+1];
		int dp[n+1][m+1];
	
		int val = 0;
		for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
				dp[i][j] = INF;
			}
		}
		dp[1][1] = 0;		
		int i,j;		
		for(i = 1 ; i <= n ;i++){
			for(j = 1 ; j <= m ;j++){
				cin>>val;
				arr[i][j] = val;
				if( i +  val <= n ){
                    dp[i + val][j] = min(dp[i + val][j], 1 + dp[i][j]);
                }
                if (j + val <= m){
                    dp[i][j + val] = min(dp[i][j + val], 1 + dp[i][j]);
                }
			}
			
		}
		if( dp[n][m] != INF)
			cout<<dp[n][m]<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}
