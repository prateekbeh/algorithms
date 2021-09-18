/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> freq;
        vector<int> res;
        for(auto word:words){
            // for every word we have its count
            freq[word]++;
        }
        int ws = 0;
        int words_size = words.size();
        int word_length = words[0].length();
        for(int i = 0 ; i <= int( s.length() - words_size * word_length) ; i++){
            unordered_map<string,int> word_seen;
            for(int j = 0 ; j < words_size ; j++){

                int next_index =  i + j * word_length;
                string word = s.substr(next_index,word_length);
                if(freq.find(word) == freq.end()){
                    break;
                }
                word_seen[word]++;
                if(word_seen[word] > freq[word]){
                    break;
                }
                if(j + 1 == words_size){
                    res.push_back(i);
                }
            }
        }
        return res;  
    }
};
// @lc code=end

