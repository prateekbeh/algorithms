#include<bits/stdc++.h>

using namespace std;

int main()
{

	int t;
	cin>>t;
	int ans = 0;
	while(t--)
	{
		int n;
		cin>>n;
		int tmp = n;
		int ans = -1;
		do{
			int unit = (tmp%10);
			ans = max(ans,unit);
			tmp = tmp/10;
		}while(tmp != 0);
		cout<<ans<<endl;
	}
	return 0;
}
				
