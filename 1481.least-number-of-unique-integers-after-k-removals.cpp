/*
 * @lc app=leetcode id=1481 lang=cpp
 *
 * [1481] Least Number of Unique Integers after K Removals
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
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> freq_map;
        for(auto num : arr){
            freq_map[num]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> minheap;

        for(auto entry : freq_map){
            minheap.push(entry);
        }

        while( k > 0 && !minheap.empty()){
            auto elm = minheap.top();
            int val = elm.first;
            int count = elm.second;
            minheap.pop();
            if(count != 1)
                minheap.push(make_pair(val,count-1));
            k -= 1;
        }
        return minheap.size();
    }
};
// @lc code=end

