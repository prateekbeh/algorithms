#include<bits/stdc++.h>


#include <cmath>

inline bool is_integer(float k)
{
  return std::floor(k) == k;
}

using namespace std;

bool prime[1000000 + 5];

void sieve( int n ) {

	for(int p = 2 ; p * p <= n ; p++){
		prime[p] = true;
		if(prime[p] == true){
			for( int x = p * p ; x <= n ; x += p ){
				prime[x] = false;
			}
		}
	}
}
			

bool isPerfectSquare(int x)
{
    // Find floating point value of
    // square root of x.
    long double sr = sqrt(x);
 
    // If square root is an integer
    return ((sr - floor(sr)) == 0);
}

int main()
{
	int t;
	cin>>t;

	//use sieve to get all the prime numbers . O( n * log ( log n ))

	memset(prime , true , sizeof(prime));
	sieve( 1e6 );

	int prime2[1000001];
	memset(prime2 , 0 , sizeof(prime2));	
	for(int i = 1 ; i <= 1000000 ; i++){
		int ans = 0;
		if(prime[i]){
			for(int b = 1 ;  b * b * b * b <= i; b++){
				 if (isPerfectSquare(i - b * b * b * b)) {
                    	ans++;
                    	break;
                 }
			}
		}
		prime2[i] = prime2[i-1] + ans;
	}

	while(t--){
		int n;
		cin>>n;
		cout<<prime2[n]<<endl;
	}
	return 0;
}
