#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int n;
	cin>>n;
	ll arr[100005] = {0};
	for(int i = 0 ; i < n  ; i++){
		cin>>arr[i];
	}
	sort(arr , arr + n );
	ll prefix_sum[100005] = {0};
	prefix_sum[0] = arr[0];
	for(int i = 1 ; i < n  ; i++){
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }
	for(int i = n - 2 ; i >= 0 ; i--){
		if( 2 * prefix_sum[i] < arr[i+1]){
			cout<<n - i - 1<<endl;
			return 0;
		}
	}
	cout<<n<<endl;
	return 0;
}
