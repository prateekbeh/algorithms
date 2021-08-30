#include<bits/stdc++.h>

using namespace std;

int hmap1[26];
int hmap2[26];

pair<bool,bool> check_hmaps(){
	bool flag = true;
	bool ans = true;
	for(int i = 0 ; i < 26 ; i++){
		if(hmap2[i] != hmap1[i]){
			ans = false;
			if(hmap2[i] > hmap1[i]){
				flag = false;
			}
		}
	}
	pair<bool,bool> ret = make_pair(ans,flag);
	return ret;
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	s1.swap(s2);
	int len1 = s1.length(), len2 = s2.length();
	int ws = 0;
	for(int i = 0 ; i < len1; i++){
		hmap1[s1[i] - 'a']++;
	}
	pair<bool,bool> ret;
	vector<int> ans;
	
	for(int we = 0 ; we < len2 ; we++){
		hmap2[s2[we] - 'a']++;
		ret = check_hmaps();
		if(!ret.second){
			hmap2[s2[ws] - 'a']--;
			ws++;
			pair<bool , bool> ret1 = check_hmaps();
			if(ret1.first){
				ans.push_back(ws);
			}
		}
		if(ret.first){
			ans.push_back(ws);
		}
	}
	//cout<<ans.size()<<endl;
	for(auto it = ans.begin() ; it != ans.end() ; it++){
		cout<<*it<<" ";
	}	
	return 0;
}
