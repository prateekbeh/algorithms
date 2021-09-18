/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int len = nums.size();
        int ws = 0,res = 0;
        int cum_product = 1;
        if(k<=1) return res;
        for(int we = 0 ; we < len ; we++)
        {
            cum_product *= nums[we];
            while(cum_product >= k){
                cum_product /= nums[ws];
                ws++;
            }
            res += (we - ws + 1);
        }
        return res;
    }
};
// @lc code=end

