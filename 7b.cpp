#include<bits/stdc++.h>

using namespace std;

int arr[35][35];
int n;
bool poss = false;

int solve(int i , int j, int res){
	if( i == n-1 && j == n-1){
		if(arr[i][j] == 1){
			poss  = true;
			return 1;
		}
		else if( arr[i][j] == 0){
			poss = true;
			return 0;
		}
		else{
			return 0;
		}
	}
	else{
		if(arr[i][j] == -1)
			return 0;

		//search from valid paths
		else if(arr[i][j] == 0){
			if(i == n-1)
				return solve(i,j+1,res);
			if( j == n-1)
				return solve(i+1,j,res);
			res = max(solve(i,j+1,res),solve(i+1,j,res));
			return res;
		}
		else{
			if(i == n-1)
				return 1 + solve(i,j+1,res);
			if( j == n-1)
				return 1 + solve(i+1,j,res);
			res = max(solve(i,j+1,res) , solve(i+1,j,res));
			return (res + 1);
		}
	}
}

int main()
{
	cin>>n;
	memset(arr,0,sizeof(arr));

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin>>arr[i][j];
		}
	}
	
	int ans1 = solve(0,0,0);
	// if(poss) cout<<ans1<<endl;
	cout<<"ans1 = " <<ans1<<endl;
	//int ans2 = solve2(n-1,n-1,0);
	//cout<<ans1+ans2<<endl;
	return 0;
}
