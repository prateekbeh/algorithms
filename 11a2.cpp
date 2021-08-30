#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
		
bool Compare(string a , string b){
	string ord1 = a + b;
	string ord2 = b + a;
	return ord1 > ord2;
}
	

int main()
{

	int n;
	cin>>n;
	ll a[100005];
	vector<string> s;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		s.push_back(to_string(a[i]));
	}
    sort(s.begin(), s.end(), Compare);
	for(int i = 0 ; i < n ; i++){
		printf("%s",s[i].c_str());
	}
	return 0;
}
