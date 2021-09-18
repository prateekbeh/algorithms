/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //int num_intervals = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin() , intervals.end(),
            [](const vector<int> x , const vector<int> y) {return x[0] < y[0];});
        vector<vector<int>>::iterator it = intervals.begin();
        vector<int> interval = *it++;
        int start = interval[0];
        int end = interval[1];
        while(it != intervals.end()){
            interval = *it++;
            if(interval[0] <= end){
                end = max(interval[1],end);
            }
            else{
                res.push_back({start,end});
                start = interval[0];
                end = interval[1];
            }
        }
        res.push_back({start,end});
        return res;
    }
};
// @lc code=end

