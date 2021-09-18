#include<bits/stdc++.h>
  
using namespace std;
 
#define INF 123456789
 
int main()
{
    int n;
    cin>>n;
    int arr[n+5][n+5];
    memset(arr,0,sizeof(arr));
 
    int dp[n+5][n+5];
    int dp2[n+5][n+5];
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= n ; j++){
			dp[i][j] = -INF;
		}
	}
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= n ; j++){
			dp2[i][j] = -INF;
		}
	}	
    for(int i = 1; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin>>arr[i][j];
        }
    }
	//we take the values from either the same row or th e previous row.
    dp[1][1] = arr[1][1];
    for(int t = 2 ; t <=  2 * n - 1 ; t++){
		
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				dp2[i][j] = -INF;
			}
		}

        for(int r1 = 1 ; r1 <= n ; r1++){
            for(int r2 = 1; r2 <= n ; r2++){
				int c1 = t - r1 + 1;
				int c2 = t - r2 + 1;
				
				/*
				if( c1 < 1 || c2 > n || c2 < 1 || c2 > n)
					continue;
				*/

				if(arr[r1][c1] == -1 || arr[r2][c2] == -1){
					continue;
				}
				int maxm = max(dp[r1][r2],max(dp[r1-1][r2],max(dp[r1][r2-1], dp[r1-1][r2-1])));
				
				if(maxm < 0){
					continue;
				}
				
				if(r1 == r2 && c1 == c2){
					dp2[r1][r2] = maxm + arr[r1][c1];
				}
				else{
					dp2[r1][r2] = maxm + arr[r1][c1];
					dp2[r1][r2] +=  arr[r2][c2];
				}
			}
        }
		for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                dp[i][j] = dp2[i][j];
            }
        }
		
    }
    cout<<max(0,dp[n][n])<<endl;
    return 0;
}
