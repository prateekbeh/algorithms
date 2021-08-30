#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin>>s;
	int N = s.length();
	
    int ans = 0; 		
	// a b c e a a e e e i o c
	char state[] = { 'a', 'e', 'i','o','u' };
    int lookingFor = 0;
    int lengthSoFar = 0;
    int ws =0;
    for (int we = 0; we < N ; ++we) {
        printf("\n s[%d] =  %c looking for %d  %c rl %d ans %d \n ", we, s[we], lookingFor,  state[lookingFor], lengthSoFar, ans);
		if (s[we] == state[lookingFor]) {
            ++lengthSoFar;
			if (lookingFor == 4) {
			  ans = max( ans, lengthSoFar);
			}
			lookingFor = ((lookingFor + 1) % 5);
		} else if (lookingFor > 0 && s[we] == state[lookingFor-1]) {
            ++lengthSoFar;
        }

        if (lookingFor == 0) {
          ws = we;
        }
        
    }
    cout << ans;
	return ans;
}
