/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start

class compare{
    public:
        bool operator()(const pair<char, int> &a , const pair<char,int> &b){
            return a.second < b.second;
        }
};
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq_map;
        for(auto chr : s){
            freq_map[chr]++;
        }
        priority_queue<pair<char,int>, vector<pair<char,int>> , compare> maxheap;

        for(auto entry : freq_map){
            maxheap.push(entry);
        }
        string res = "";
        while(!maxheap.empty()){
            int count = maxheap.top().second;
            char letter = maxheap.top().first;
            for(int i = 0 ; i < count ; i++){
                res += letter;
            }
            maxheap.pop();
        }
        return res;
    }
};
// @lc code=end

