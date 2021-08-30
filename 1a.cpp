#include<bits/stdc++.h>

using namespace std;


int n;
int arr[105][3];
int dp[105][3];
int dfs(int r , int color){
	
	if(dp[r][color] != -1){
		return dp[r][color];
	}	
	int ans = 1000000007;
	
	if(r >= n){
      // printf("\n last r %d color %d", r, color);
		return 0;
	}
	if(color == 0){
		ans = min(ans , arr[r][color] + dfs(r + 1, 1));
		ans = min(ans , arr[r][color] + dfs(r + 1, 2));
		return dp[r][color] = ans;
	}else if(color == 1){
		ans = min(ans , arr[r][color] + dfs(r + 1, 0));
        ans = min(ans , arr[r][color] + dfs(r + 1, 2));
		return dp[r][color] = ans;
	}
	else{
		ans = min(ans , arr[r][color] + dfs(r + 1, 0));
        ans = min(ans , arr[r][color] + dfs(r + 1, 1));
		return dp[r][color] = ans;
	}

	/*	
    int v1  = dfs(r + 1, (color + 1)%3);
    int v2  = dfs(r + 1, (color + 2)%3);
    int v = min(v1, v2) + arr[r][color]; 
    printf("\n r %d c %d  v1 %d v2 %d v  %d ",r, color, v1, v2, v);
    return ans = min(ans , v);
	*/
}
int main()
{
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 3 ; j++){
			cin>>arr[i][j];
		}
	}
	for(int i = 0 ; i < 105 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            dp[i][j] = -1;
        }
    }
	int ans = 1000000007;
	for(int i = 0 ; i < 3 ; i++){
		ans = min(ans, dfs(0,i));
	}
	cout<<ans<<endl;	
	return 0;
}
/*

if(color == 0){
		ans = min(ans , arr[r][color] + dfs(r + 1, 1));
		return ans = min(ans , arr[r][color] + dfs(r + 1, 2));
	}else if(color == 1){
		ans = min(ans , arr[r][color] + dfs(r + 1, 0));
        return ans = min(ans , arr[r][color] + dfs(r + 1, 2));
	}
	else{
		ans = min(ans , arr[r][color] + dfs(r + 1, 0));
        return ans = min(ans , arr[r][color] + dfs(r + 1, 1));
	}

*/
