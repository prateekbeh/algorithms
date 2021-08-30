#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	string s;
	int k;
	cin>>s>>k;
	int len = s.length();
	int dp[len];
	fill_n(dp,len,1);
	int p = 0;
	for(int i = 1 ; i < len ; i++){
		p = abs(s[i] - s[i-1]);
		if(p <= k){
			dp[i] = dp[i-1] + 1;
		}
	}
		
	int maxi = -1e9;
	int pos = -1;
	for(int i = 0 ; i < len ; i++){
		if(maxi < dp[i]){
			maxi = dp[i];
			pos = i;
		}
	}
	for(int i = pos - maxi + 1 ; i <= pos ;i++){
		cout<<s[i];
	} 

	return 0;
}
