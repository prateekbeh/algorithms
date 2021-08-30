#include<bits/stdc++.h>

using namespace std;

int main()
{

	int n;
	cin>>n;
	int arr[n];
	memset(arr,0,sizeof(arr));
	int cum_sum[n+1];	
	int cum_sum1[n+1];	
	memset(cum_sum,0,sizeof(cum_sum));
	memset(cum_sum1,0,sizeof(cum_sum1));
	cum_sum[0] = 0;
	cum_sum1[0] = 0;
	int tmp = 0;
	for(int i = 1 ; i <= n ; i++){
		cin>>arr[i];
		tmp = (arr[i] == 1) ? 1 : - 1;
		cum_sum[i] = cum_sum[i-1] + tmp;
	}
	for(int i = 1 ; i <= n ; i++){
		tmp = (arr[n-i+1] == 1) ? 1 : - 1;
		cum_sum1[i] = cum_sum1[i-1] + tmp;
	}
	/*
	for(int i = 0 ; i <= n ; i++){
		cout<<cum_sum[i]<<" "<<cum_sum1[i]<<endl;
	}
	*/
	int k = 0;
	for( k = 0 ; k <= n ; k++){
		if(cum_sum[k] > cum_sum1[n-k]){
			break;
		}
	}
	cout<<k<<endl;
	return 0;
}
	
