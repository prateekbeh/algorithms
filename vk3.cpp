#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{

	int t;	
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		int b[n];
		ll sum_a = 0;
		ll sum_b = 0;
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
			sum_a += a[i];
		}
		for(int j = 0 ; j < n ; j++){
			cin>>b[j];
			sum_b += b[j];
		}
		sort(a,a+n);
		sort(b,b+n);
		int id = 0;
		for(id = 0 ; id < n/4 ; id++){
			sum_a -= a[id];
			sum_b -= b[id];
		}
		int ans = 0;
		while(1){
			if(sum_b - sum_a <= 0){
				cout<<ans<<endl;
				break;
			}
			else{
				sum_a += 100;
				if(id >= 0)
					sum_b += b[id--];
				ans++;
			}
		}
	}
	return 0;
}
		
