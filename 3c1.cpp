#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool compare(const pair< pair<int,int> , int > a, const pair<pair<int,int>, int > b){
    return a.first.second < b.first.second;
}

int main()
{

	int n;
	cin>>n;
	ll arrival[n], duration[n], profit[n];
	for(int i = 0 ; i < n ; i++){
		cin>>arrival[i];
	}
	
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>duration[i];
	}
	
	cin>>n;
	pair< pair<int,int>, int > finish[n];
	for(int i = 0 ; i < n ; i++){
		cin>>profit[i];
		finish[i] = make_pair(make_pair(arrival[i] , arrival[i] + duration[i]),profit[i]);
	}
	
	map<int,int> dp;
	sort(finish, finish+n , compare);	
	dp[0] = 0;
	for(int i = 0 ; i < n ; i++){
		int prof = prev(dp.upper_bound(finish[i].first.first))->second + finish[i].second;
		if(prof > dp.rbegin()->second)
			dp[finish[i].first.second] = prof;
		
	}
	cout<<dp.rbegin()->second<<endl;
	return 0;
}

