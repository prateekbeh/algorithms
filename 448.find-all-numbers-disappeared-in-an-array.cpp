/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i = 0;
        vector<int> res;
        int index = -1;
        while( i < nums.size()){
            index = nums[i] - 1;
            if( nums[i] != nums[index]){
                swap(nums, i , index);
            }else{
                i++;
            }
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != i + 1){
                res.push_back(i+1);
            }
        }
        return res;
    }
    void swap(vector<int>& arr, int i,int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

    }
};
// @lc code=end

