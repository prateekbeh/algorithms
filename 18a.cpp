#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	memset(arr,0,sizeof(arr));
	int freq[1000005];
	memset(freq,0,sizeof(freq));
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
		freq[arr[i]]++;
	}
	sort(freq,freq+1000005,greater<int>());
	ll sum = 0;
	int ans = 0;
	int threshold = (n%2 != 0) ? (n/2+1) : (n/2);
	for(ans = 0 ; ans < 1000005 ; ans++){
		
		if( sum >= threshold){
			break;
		}
		else{
			sum += freq[ans];
		}
	}
	cout<<ans<<endl;
	return 0;
}
	
