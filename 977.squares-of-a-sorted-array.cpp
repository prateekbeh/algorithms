/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());

        int st = 0;
        int index = nums.size() - 1;
        int en = nums.size() - 1;
        while(st <= en){
            if(nums[st] * nums[st] >= nums[en]*nums[en]){
                res[index--] = (nums[st] * nums[st]);
                st++;
            }else{
                res[index--] = (nums[en] * nums[en]);
                en--;
            }
        }
        return res;
    }
};


// @lc code=end

