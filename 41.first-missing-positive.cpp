/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        long long index = -1;
        
        while(i < nums.size()){
            index = nums[i] - 1;
            if(i == 7) cout<< nums[i]<<endl; 
            if(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[index]){
                swap(nums, i, nums[i] - 1);
            }else {
                i++;
            }  
        }
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
    void swap(vector<int> &arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};
// @lc code=end

