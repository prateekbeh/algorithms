#include<bits/stdc++.h>

using namespace std;


int ans = 0;
int arr[1005][1005];
int m , n;
int main(){
	cin>>m>>n;
	int arr[m][n];
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			cin>>arr[i][j];
		}
	}
	int dp[1005][1005];
	for(int i = 1 ; i <= m ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(arr[i-1][j-1] == 1){
				dp[i][j] = min(dp[i][j - 1] , min( dp[i-1][j], dp[i-1][j-1])) + 1;
				ans = max(ans , dp[i][j]);
			}
		}
	}
	cout<<ans * ans<<endl;
	return 0;
}
