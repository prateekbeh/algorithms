/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int num = 0;
       for(int i = 0 ; i < nums.size() ; i++){
           num = num ^ nums[i];
       } 
       return num;
    }
};
// @lc code=end

