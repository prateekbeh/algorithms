#include<bits/stdc++.h>
  
using namespace std;
 
#define INF 123456789
 
int main()
{
    int n;
    cin>>n;
    int arr[n+5][n+5];
    memset(arr,0,sizeof(arr));
 
    int dp[n+5][n+5][n+5][n+5];
    memset(dp,-INF,sizeof(dp));
 
    for(int i = 1; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin>>arr[i][j];
        }
    }
    dp[1][1][1][1] = arr[1][1];
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            for(int k = 1 ; k <= n ; k++){
					int l = i + j - k;
					if( l < 1 || l > n)
						continue;
                    if(arr[i][j] == -1 || arr[k][l] == -1){
						//cout<<"i = " << i << " j = " <<j << " k = "<<k << " l = " << l << " dp[i][j][k][l] = " << dp[i][j][k][l]<<endl;
                        continue;
                    }
                    int maxm = max(dp[i-1][j][k-1][l],max(dp[i-1][j][k][l-1],max(dp[i][j-1][k-1][l], dp[i][j-1][k][l-1])));
                    if(maxm < 0){
						
						//cout<<"i = " << i << " j = " <<j << " k = "<<k << " l = " << l << " dp[i][j][k][l] = " << dp[i][j][k][l]<<endl;
                        continue;
                    }
                    if(i == k && j == l){
                        dp[i][j][k][l] = maxm + arr[i][j];
                    }
                    else{
                        dp[i][j][k][l] = maxm + arr[i][j];
                        dp[i][j][k][l] +=  arr[k][l];
                    }
					//cout<<"i = " << i << " j = " <<j << " k = "<<k << " l = " << l << " dp[i][j][k][l] = " << dp[i][j][k][l]<<endl;
            }
        }
    }
    cout<<max(0,dp[n][n][n][n])<<endl;
    return 0;
}
