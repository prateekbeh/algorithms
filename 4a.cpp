#include<bits/stdc++.h>
using namespace std;

#define INF 1e9 

bool poss = false;
int arr[1005];
int dp[1005][1005];

int solve(int n , int m , int M)
{
	if( n == 0 ){
		poss = true;
		return 0;
	}
	if( n < 0 || m == M){
		return INF;
	}
	
	if(dp[n][m] != -1) return dp[n][m];
	int a = min(1 + solve(n-arr[m],m,M),1 + solve(n-arr[m],m+1,M));   	
	int b = min(a, solve(n,m+1,M));
	return dp[n][m] = b;
}
	
int main()
{
	int m;
	cin>>m;
	for(int i = 0 ; i < m ; i++)
		cin>>arr[i];
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	int res = solve(n,0,m);
	if(poss) cout<<res<<endl;
	else cout<<-1<<endl;
	return 0;
}
