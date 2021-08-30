#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int x,y,p,q;
	cin>>x;
	int X[1000] = {0};
	for(int i = 0 ; i < x ; i++){
        cin>>X[i];
    }
	
	cin>>y;
	int Y[1000] = {0};
	for(int i = 0 ; i < y ; i++){
        cin>>Y[i];
    }

	cin>>p;			
	int P[1000] = {0};
	for(int i = 0 ; i < p ; i++){
        cin>>P[i];
    }
	
	cin>>q;
    int Q[1000] = {0};
	for(int i = 0 ; i < q ; i++){
        cin>>Q[i];
    }
	int budget;
	cin>>budget;

	vector<ll> A;
	for(int i = 0 ; i < x ; i++){
		for(int j = 0 ; j < y ; j++){
			A.push_back(X[i] + Y[j]);
		}
	}
	vector<ll> B;
	for(int i = 0 ; i < p ; i++){
		for(int j = 0 ; j < q ; j++){
			B.push_back(P[i] + Q[j]);
		}
	}
	sort(B.begin() , B.end());
	ll ans = 0;
	for(int i = 0 ; i < x * y ; i++){
		ll key = A[i];
		ans += upper_bound(B.begin() , B.end() , budget - key) - B.begin();
	}
	cout<<ans<<endl;
	return 0;
}
