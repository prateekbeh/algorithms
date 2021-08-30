#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define INF 123456789

int main()
{
	string str,pattern;
	cin>>pattern>>str;
	/*
	int windowStart = 0, matched = 0, minLength = str.length() + 1, subStrStart = 0;
    unordered_map<char, int> charFrequencyMap;
    for (auto chr : pattern) {
      charFrequencyMap[chr]++;
    }

    // try to extend the range [windowStart, windowEnd]
    for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
      char rightChar = str[windowEnd];
      if (charFrequencyMap.find(rightChar) != charFrequencyMap.end()) {
        charFrequencyMap[rightChar]--;
        if (charFrequencyMap[rightChar] >= 0) {  // count every matching of a character
          matched++;
        }
      }

      // shrink the window if we can, finish as soon as we remove a matched character
      while (matched == pattern.length()) {
        if (minLength > windowEnd - windowStart + 1) {
          minLength = windowEnd - windowStart + 1;
          subStrStart = windowStart;
        }

        char leftChar = str[windowStart++];
        if (charFrequencyMap.find(leftChar) != charFrequencyMap.end()) {
          // note that we could have redundant matching characters, therefore we'll decrement the
          // matched count only when a useful occurrence of a matched character is going out of the
          // window
          if (charFrequencyMap[leftChar] == 0) {
            matched--;
          }
          charFrequencyMap[leftChar]++;
        }
      }
    }

    cout<<str.substr(subStrStart, minLength);


	*/
	int ans = str.length() + 1;
	int matched = 0;
	int start = 0;
	unordered_map<char, int> mp;
	int len1 = pattern.length(), len2 = str.length();
	for(int i = 0 ; i < len1; i++){
		mp[pattern[i]]++;
	}
		
	int ws = 0;
	for(int we = 0 ; we < len2 ; we++){
		if(mp.find(str[we]) !=  mp.end()){
			//match every instance of the pattern.
			// if the pattern is ab it matched will be 2.	
			mp[str[we]]--;
			if(mp[str[we]] >= 0){
				matched++;
			}
		}		
		while(matched == len1){
			
			if( we - ws + 1 < ans){
				ans = we - ws + 1;
				start = ws;
			}
			
			if(mp.find(str[ws]) !=  mp.end()){
				if(mp[str[ws]] == 0){
					matched--;
				}
				// this is added to put back the useful character.
				mp[str[ws]]++;
			}
			ws++;
		}
	}
	cout<<str.substr(start,ans);		
	
	return 0;
}
