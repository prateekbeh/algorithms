#include<bits/stdc++.h>

using namespace std;

bool prime[1000005];
int dp[1000005];

void sieve(int n)
{
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
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

void count_ans(int n)
{
    for (int i = 2; i <= n; i++) {
 
        // Check whether the number
        // is prime or not
		int answer = 0;
        if (prime[i]) {
 
            // Iterate for values of b
            for (int j = 1;
                 j * j * j * j <= i;
                 j++) {
 
                // Check condition for a
                if (
                    isPerfectSquare(
                        i - j * j * j * j)) {
                    answer++;
                    break;
                }
            }
        }
		dp[i] = dp[i-1] + answer;
    }
}

int main()
{
	int t;
	cin>>t;
	sieve(1e6 + 5);	
	count_ans(1e6 + 5);
	dp[1] = 0;
	while(t--){
		int n;
		cin>>n;
		cout<<dp[n]<<endl;
	}
	return 0;
}
