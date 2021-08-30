#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> power_set(int arr[],int n){
	
	//int n = sizeof(arr)/sizeof(int);
	vector<ll> pset;
    for( int mask = 0; mask < pow(2,n) ; mask++){
        ll sum = 0;
        for(int i = 0; i < n ; i++){
            if((1 << i) & mask){
                sum += arr[i];
			}
		}
        pset.push_back(sum);
	}
    return pset;
}
int main()
{
	int n;
	cin>>n;
	int a1[22] = {0};
	int a2[22] = {0};
	int size_a1 = 0;
	int size_a2 = 0;
	int val = 0;
	int idx = 0;
	for(int i = 0 ; i < n ; i++){
		cin>>val;
		if( i < n/2 ){
			a1[i] = val;
			size_a1++;
		}
		else{
			a2[idx++] = val;
			size_a2++;
		}
	}
	ll max_cap;
	cin>>max_cap;	
	vector<ll> pset_left = power_set(a1, size_a1);
	vector<ll> pset_right = power_set(a2,size_a2);

	sort(pset_right.begin() , pset_right.end());
	
	ll ans = 0;
	for(auto i = 0 ; i != pset_left.size() ; i++){
		ll key = pset_left[i];
		auto it = upper_bound(pset_right.begin() , pset_right.end() , max_cap - key);
		if( it != pset_right.begin()){
			it--;
		}
		if( key + (*it) <= max_cap){
			ans = max(ans, key + (*it));
		}
	}
	cout<<ans<<endl;
	return 0;
}
