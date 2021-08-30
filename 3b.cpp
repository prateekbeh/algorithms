#include<bits/stdc++.h>

using namespace std;

int main()
{

	int n;
	cin>>n;
	long long s[n];
	cin>>s[0];
	int k,b,m;
	cin>>k>>b>>m;
	long long a;
	cin>>a;
	
	for(int i = 1 ; i < n ; i++){
		s[i] = ((k%m) * s[i-1]%m + (b%m))%m + 1 + s[i-1];
	}
	for(int i = 0 ; i < n ; i++)
		cout<<s[i]<<" ";

	long long res = 0;
	for(int l = 0, r = n-1 ; l <= r ; ){
		if( s[l] * s[r] <= a ){
			res += 2 * (r-l)+1;
			l++;
		}
		else{
			r--;
		}
	}
	cout<<res<<endl;
}
