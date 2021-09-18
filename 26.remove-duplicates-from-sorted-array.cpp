/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nextNonDuplicate = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            if (nums[nextNonDuplicate - 1] != nums[i]) {
                nums[nextNonDuplicate] = nums[i];
                nextNonDuplicate++;
            }
        }
        return nums.size() == 0 ? 0 : nextNonDuplicate;
    }
    
};
// @lc code=end

