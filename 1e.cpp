#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	
	int n , q;
	cin>>n>>q;
	int a[200005] = {0};
	int b[200005] = {0};
	int val[200005] = {0};
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	int l , r;
	for(int i = 0 ; i < q ; i++){
		cin>>l>>r;
		l--; r--;
		val[l]++;
		val[r+1] = ( r < n - 1) ? val[r+1] - 1 : val[r+1];
	}
	//uses prefix sum.
	int v = 0;
	for(int i = 0 ; i < n ; i++){
		v += val[i];
		b[i] = v;
	}
	cout<<endl;
	sort(a , a+n);
	sort(b , b + n);
	ll res = 0;
	for(int i = 0 ; i < n ; i++){
		res +=  ( 1ll * b[i] * a[i] );
	}
	cout<<res<<endl;
}
