//https://leetcode.com/discuss/interview-question/371225/Sorted-Arrangements-or-Infosys-Specialist-Programmer-or-On-campus-hackerrank

#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

ll BIT[100005], a[100005], n;
void update(ll x, ll delta)
{     
      for(; x <= n; x += x&-x){
        BIT[x] += delta;
      }
}

ll query(ll x)
{
     ll sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
} 
 
ll getCount( ll number, ll i){
    ll left = query(number-1);
    ll right = i - query(number);
    return left < right ? 2*left+1 : 2*right+1; 
}

ll minimumOperations(vector<ll> numbers) {
    ll ans=0;
    n = 0;
    for(int i=0;i<numbers.size();i++){
         n = max(n, numbers[i]);
    }
    for(int i=0; i<numbers.size(); i++){
        ans += getCount(numbers[i], i);
        update(numbers[i],1);
    }
    return ans;
}

int main(){
	int m;
	cin>>m;
	int val = 0;
	vector<ll> v;	
	for(ll i = 0 ; i < m ; i++){
		cin>>val;
		v.push_back(val);
	}
	cout<<minimumOperations(v);
	return 0;
}
