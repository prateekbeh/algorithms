/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            if(nums[i] < nums.size() && nums[i] != nums[nums[i]]){
                swap(nums,i,nums[i]);
            }else{
                i++;
            }

        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != i){
                return i;
            }
        } 
        return nums.size();
    }
    void swap(vector<int>& arr, int i,int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

    }
};
// @lc code=end

