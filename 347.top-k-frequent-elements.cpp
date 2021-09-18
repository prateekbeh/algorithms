/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start

class compare{
    public:
        bool operator()(const pair<int,int> &a, const pair<int,int> &b){
            return a.second > b.second;
        }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq_map;
        for(int i = 0 ; i < nums.size() ; i++){
            freq_map[nums[i]]++;
        }
        priority_queue<pair<int , int > ,vector<pair<int ,int>>, compare> minheap; 

        for(auto entry : freq_map){
            minheap.push(entry);
            if(minheap.size() > k){
                minheap.pop();
            }
        }
        vector<int> topNumbers;
        while (!minheap.empty()) {
            topNumbers.push_back(minheap.top().first);
            minheap.pop();
        }
        return topNumbers;
    }
};
// @lc code=end

