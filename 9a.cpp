#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int n;
	cin>>n;
	int container[n];
	memset(container,0,sizeof(container));
	for(int i = 0 ; i < n ; i++){
		cin>>container[i];
	}
	ll tar;
	cin>>tar;
	ll sum = 0;
	for(int i = 0 ; i < n ; i++){
		sum += container[i];
		if(sum >= tar){
			break;
		}
	}
	cout<<abs(tar - sum)<<endl;
	return 0;
}
		
