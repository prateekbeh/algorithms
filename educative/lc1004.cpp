#include<bits/stdc++.h>

using namespace std;

int main(){

	int arr[1005];
	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	int ans = 0;
	int bmap[2] = {0};
	int ws = 0;
	for(int we = 0 ; we < n; we++){
		bmap[arr[we]]++;
        if( bmap[0] > k ){
        	bmap[arr[ws]]--;
            ws++;
        }
        ans = max(ans,we-ws+1);
    }
	cout<<ans<<endl;
    return 0;
}
