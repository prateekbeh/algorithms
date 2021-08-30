#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> arr;
	int inp = 0;
	for(int i = 0 ; i < n ; i++){
		cin>>inp;
		arr.push_back(inp);
	}
	sort(arr.begin() , arr.end());
	int ans = 2;
	for(int i = 0 ; i < n-1; i++){
		int smallest_sum = arr[i] + arr[i+1];
		int pos = lower_bound(arr.begin(),arr.end(),smallest_sum) - arr.begin();
		ans = max(ans, pos-i);
	}
	cout<<ans<<endl;
	return 0;
}
