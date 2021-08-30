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
	
	ll dp[50000];

	memset(dp,0,sizeof(dp));
	sort(finish, finish+n , compare);	
	dp[0] = finish[0].second;
	for(int i = 1 ; i < n ; i++){
		dp[i] = finish[i].second;
		for(int j = 0 ; j < i ; j++){
			if(finish[i].first.first >= finish[j].first.second && dp[i] < dp[j] + finish[i].second){
				dp[i] =  max(dp[i-1], dp[j] + finish[i].second);
			}
		}
	}
	cout<<dp[n-1]<<endl;
	return 0;
}

