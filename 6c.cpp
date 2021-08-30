#include<bits/stdc++.h>

using namespace std;

int main()
{

	int n,m;
	cin>>n>>m;
	int arr[n+1][m+1];
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= m ; j++){
			if( i == 0 || j == 0){
				arr[i][j] = 0;
			}else{
				cin>>arr[i][j];
			}
		}
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cout<< arr[i][j] +  arr[i-1][j-1] -( arr[i-1][j] + arr[i][j-1]) << " ";
		}
		cout<<endl;
	}
	return 0;
}
