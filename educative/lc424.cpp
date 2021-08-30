#include<bits/stdc++.h>

using namespace std;

int main()
{

	string s;
	cin>>s;
	int len = s.length();
	int k;
	cin>>k;
	int ws = 0;
	int hmap[128] = {0};
	int ans = 0;
	int maxLetterCount = 0;
	
	for(int we = 0 ; we < len ; we++){
		hmap[s[we]]++;
		maxLetterCount = max(maxLetterCount, hmap[s[we]]);
		if( we - ws + 1 - maxLetterCount > k ){
			hmap[s[ws]]--;
			ws++;
		}
		ans = max(ans,we-ws+1);
	}
	cout<<ans<<endl;
	return 0;
}
		
			
