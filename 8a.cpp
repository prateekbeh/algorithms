#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll total,n,m;
	cin>>total>>n>>m;
	vector<pair<ll, ll> > arr;
	ll st,en;
	arr.push_back(make_pair(0,0));
	for(int i = 1 ; i <= n ; i++){
		cin>>st>>en;
		arr.push_back(make_pair(st,en));
	}
	arr.push_back(make_pair(total+1,total+1));
	sort(arr.begin(),arr.end());
	ll ans = 0;
	for(int i = 1 ; i < n + 2 ; i++){
		ll gap = (arr[i].first - arr[i-1].second - 1);
		ans += __builtin_popcountll(gap);
	}
	cout<<ans<<endl;
	return 0;
}
