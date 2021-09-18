/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& arr) {
        int s = arr[0].size();
        for (int row = 0; row < arr.size(); row++) {
            for (int col = 0; col < (s + 1) / 2; ++col) {
                int tmp = arr[row][col] ^ 1;
                arr[row][col] = arr[row][s - 1 - col] ^ 1;
                arr[row][s - 1 - col] = tmp;
            }
         }
        return arr;
    }
};
// @lc code=end

