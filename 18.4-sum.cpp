/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int len = nums.size();
        vector<vector<int>> quadruplets;
        if(nums.size() < 4) return quadruplets; 
        for(int i = 0 ; i < nums.size() - 3 ; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i + 1; j < nums.size() - 2 ; j++){
                if(j > i + 1 && nums[j] == nums[j-1]){
                    continue;
                }
                searchPairs(nums, target, i, j, quadruplets);
            }
        }
        return quadruplets;
    }
    void searchPairs(const vector<int> &arr, long long targetSum, int first,int second,
                         vector<vector<int>> &quadruplets) {
        int left = second + 1;
        int right = arr.size() - 1;
        while (left < right) {
            long long sum1 = arr[first] + arr[second];
            long long sum2 = arr[left] + arr[right];
            long long currentSum = sum1 + sum2;
            if (currentSum == targetSum) { // found the pair
                quadruplets.push_back({arr[first],arr[second],arr[left],arr[right]});
                left++;
                right--;
                while (left < right && arr[left] == arr[left - 1]) {
                left++; // skip same element to avoid duplicate triplets
                }
                while (left < right && arr[right] == arr[right + 1]) {
                right--; // skip same element to avoid duplicate triplets
                }
            } else if (targetSum > currentSum) {
                left++; // we need a pair with a bigger sum
            } else {
                right--; // we need a pair with a smaller sum
            }
        }    

    }
};
// @lc code=end

