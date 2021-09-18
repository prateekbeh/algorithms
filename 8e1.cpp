#include<bits/stdc++.h>
 
using namespace std;
 
#define INF 123456789
 
int arr[1004][1004];
int dp[1004][1004]; 
int n,m;
int solve(int row, int col){
	if(dp[row][col] != INF ) return dp[row][col];
	if( row == n  && col == m){
		return 0;
	}
	if(arr[row][col] == 0){
		return INF;
	}
	
	int down = INF;
	int right = INF;
	if( row + arr[row][col] <= n)
		down = 1 + solve( row + arr[row][col] ,col);
	if(col + arr[row][col] <= m)
		right = 1 + solve( row  ,arr[row][col]+ col);

	dp[row][col] = min(down,right);
	//cout<< dp[row][col] << endl;
	return dp[row][col];
}
 
int main()
{
    int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				cin>>arr[i][j];
				dp[i][j] = INF;
			}
		}
		int ans = solve(1,1);
		//cout<<ans<<endl;
		if(ans < INF){
			cout<<ans<<endl;
		}
		else{
			cout<<-1<<endl;
		}
		//ans = INF;
	} 		
	return 0;
}

/*
#include<bits/stdc++.h>

using namespace std;

#define INF 123456789

int ans = INF;
int arr[1004][1004];

int n,m;
void solve(int row, int col , int steps){
	
	
	if( row > n || col > m){
		return;
	}
	
	if( row == n  && col == m){
		ans = steps;
		return;
	}
	if(row + arr[row][col] <= n)
		solve( row + arr[row][col] , col , steps + 1);
	if(arr[row][col]+ col <= m)
		solve( row  ,arr[row][col]+ col , steps + 1);
}

int main()
{
    int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				cin>>arr[i][j];
			}
		}
		solve(1,1,0);
		if(ans != INF){
			cout<<ans<<endl;
		}
		else{
			cout<<-1<<endl;
		}
		ans = INF;
	} 		
	return 0;
}
*/
