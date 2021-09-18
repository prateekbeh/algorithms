#include<bits/stdc++.h>

using namespace std;

typedef long long  ll;
const int  mod = 1e9 + 7;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		n++;
		ll sum = 0;
		ll block = 0;
		ll quotient = 0;
		ll remainder = 0;
		ll pow10  = 1;
		ll pow2 = 1;
		for(int i = 0; i <= 60 ; i++){
			block = pow2;
			quotient = n/block;
			remainder = n%block;
			
			sum += (1ll * ( ( 1ll * (block % mod) * ((quotient/2)%mod )) % mod) *  pow10 ) % mod;

			if(quotient % 2 != 0){ 
				sum += ( 1ll * (remainder % mod) * pow10 )% mod;
			}
            pow10 = (pow10 * 10) % mod;
			pow2 = (pow2 * 2) ;
		}
		cout<<sum<<endl;
	}
	return 0;
}
