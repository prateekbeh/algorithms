#include<bits/stdc++.h>

using namespace std;


#define MINI 1234567890

map<int, pair<int, pair<int, int> > > dp;

int main()
{
	int n;
	cin>>n;

	int arr[n];
	memset(arr,0,sizeof(arr));
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
	}
	
	int min1, min2;
	dp[arr[0]] = make_pair(1, make_pair(arr[0], MINI));
	for(int k = 1 ; k < n ; k++){
			
		auto it = dp.upper_bound(arr[k]);
		if(it->second.first != 0){
			min1 = it->second.second.first;
        	min2 = it->second.second.second;
        	if(arr[k] < min1){
				int tmp = min1;
				min1 = arr[k];
				min2 = tmp;
				//store in dp
				dp[min1 + min2] = make_pair(it->second.first + 1, make_pair(min1, min2));
			}else if(arr[k] < min2 && arr[k] >= min1){
				min2 = arr[k];
				dp[min1 + min2] = make_pair(it->second.first + 1, make_pair(min1, min2));
			}
			else{
				dp[min1 + min2] = make_pair(it->second.first + 1, make_pair(min1, min2));
			}
		}
		else{
			// the subsequence can start from here.
			dp[arr[k]] =  make_pair(1, make_pair(arr[k], MINI));
		}
	}		
	int res = 0;
	for(auto it = dp.begin() ; it!= dp.end() ; it++){
		cout<<it->second.first<<" ";
		res = max(res, it->second.first);
	}
	cout<<res<<endl;
	return 0;
}

//old code
	/*
	if(arr[1] < arr[0]){
		min1 = arr[1];
		min2 = arr[0];
		dp[arr[0] + arr[1]] = make_pair(2, make_pair(arr[1], arr[0]));
	}
	else{
		min1 = arr[0];
        min2 = arr[1];
		dp[arr[0] + arr[1]] = make_pair(2, make_pair(arr[0], arr[1]));
	}
	*/
//
