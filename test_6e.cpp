#include<bits/stdc++.h>

using namespace std;


#define MINI 1234567890

map<int, pair<int, pair<int, int> > > dp;

int main()
{
	dp[10] = make_pair(1, make_pair(10, MINI));
	auto it = dp.upper_bound(11);
	cout << typeid(it->second).name() << endl;
	cout<<it->second.second.second<<endl;
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
