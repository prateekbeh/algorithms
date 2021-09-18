#include<bits/stdc++.h>

using namespace std;

int arr[1000006];
typedef long long ll;
const int mod = 1e9 + 7;
void solve(int n , int k){
	
	ll now = 0;
	bool not_exceeded = true;
	for(int i = 0 ; i < k ; i++){
		int digit = arr[i]%10;
        if(digit < 2 ||  (now < 2 && not_exceeded)){
            now += digit;
		}
        else{
            now *= digit;
		}
        if(now >= mod){
            now %= mod;
            not_exceeded = false;
		}
    }    
    cout<< (now%mod) <<endl;
}
		

int main()
{
	int n,k;
	cin>>n>>k;
	for(int i = 0 ; i < k ; i++){
		cin>>arr[i];
	}
	solve(n,k);	
	return 0;
}
