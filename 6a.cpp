#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cal_sum(int st , int len)
{
	return st * len + (len * (len-1)/2);
}

int main()
{
	ll res = 0;
	ll i,j,k;
	cin>>i>>j>>k;

	int len = j - i + 1;
	res += cal_sum(i,len);
	len = j - k;
	res += cal_sum(k,len);
	cout<<res<<endl;
}
