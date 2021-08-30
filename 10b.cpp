#include<bits/stdc++.h>

using namespace std;

#define INF 123456789

int main()
{
	int n;
	cin>>n;
	int a[100005] = {0};
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	int extent[100005];
	for(int i=0;i<n;i++){
          extent[i]=-1;
    }
	for(int i = 0 ; i < n ; i++){
		int left , right;
		left = max(0,i - a[i]);
		right = min(n,i + a[i] + 1);
		extent[left] = max(extent[left] , right);
	}
	int right = extent[0];
	int next_idx = -1;
	int ans = 1;
	for(int i = 0 ; i < n ; i++){
		next_idx = max(next_idx,extent[i]);
		if( i == right){
			ans++;
			right = next_idx;
		}
	}
	cout<<ans<<endl;
	return 0;
}

	

	/*
	int dp[100005] = {0};
	dp[0] = 0;
	dp[1] = 1;
	int lwf = 1;
	for(int i = 2 ; i <= n ; i++){
		if( lwf + loc[lwf] >= i ){
			if( dp[max(0,i - loc[i] - 1)] + 1 < dp[i-1]){
				lwf = i;
				dp[i] = dp[max(0,i - loc[i] - 1)] + 1;
			}else{
				dp[i] = dp[i-1];
			}
		}
		else{
			if( dp[max(0,i - loc[i] - 1)] + 1 < dp[i-1] + 1){
				dp[i] = dp[max(0,i - loc[i] - 1)] + 1;
            }else{
                dp[i] = dp[i-1] + 1;
            }
			lwf = i;
		}
	}
	for(int i = 0 ; i <= n ; i++){
		cout<<dp[i]<<" ";
	}
	cout<<"ans = "<<dp[n]<<endl;
	
	return 0;
}*/
