/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        int index = 0;
        while( i < nums.size()  ){
            index = nums[i] - 1;
            if( nums[i] != nums[index]){
                swap(nums,i,index);
            }
            else{
                i++;
            }
        }
        int ans = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != i+1){
                ans = nums[i];
            }
        }
        return ans;
    }
    void swap(vector<int>& arr, int i,int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

    }
};
// @lc code=end

