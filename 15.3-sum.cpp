/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> triplets;
    vector<vector<int>> threeSum(vector<int>& arr) {
        if(arr.size()<3) return triplets;
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < arr.size() - 2; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) { // skip same element to avoid duplicate triplets
            continue;
        }
        searchPair(arr, -arr[i], i + 1, triplets);
        }

        return triplets;
    }

   void searchPair(const vector<int> &arr, int targetSum, int left,
                         vector<vector<int>> &triplets) {
    int right = arr.size() - 1;
    while (left < right) {
      int currentSum = arr[left] + arr[right];
      if (currentSum == targetSum) { // found the pair
        triplets.push_back({-targetSum, arr[left], arr[right]});
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

