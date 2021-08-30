#include<bits/stdc++.h>

using namespace std;


string solve(string s)
{
	if(s.length() <= 2)
		return s;
	int cnt = 1;
	//if a good string is given it always starts with 1.
	int i = 0, j = 1;
	vector<string> dp_strings;
	while(j <= s.size())
	{
		if(s[j]	== '1')
			cnt++;
		else
			cnt--;
		if(cnt == 0){
			string good_substr = s.substr(i,j-i+1);
			if(good_substr.size() == s.size()){
				// elimiate the first 1 and last 0 to solve for the subproblem.
				good_substr = s[i];
				good_substr += solve(s.substr(i+1,j-i-1)); 
               	good_substr += s[j-i];
			}else{
				good_substr = solve(good_substr);
			}
			dp_strings.push_back(good_substr);
			j = j + 1;
			i = j;
			cnt = 1;
		}
		j = j + 1; 
	}
	sort(dp_strings.begin(), dp_strings.end(), greater<string>());
	string output_s = "";
	for(string t: dp_strings)
    	output_s = output_s + t;
	
	//cout<<"output_string = "<<output_s << " Its length = " << output_s.length()<<endl;

    return output_s;
}
	

int main()
{
	string s;
	cin>>s;
	string res = solve(s);
	cout<<res.length()<<endl;
	cout<<res<<endl;
	return 0;
}
