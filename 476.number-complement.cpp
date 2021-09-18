/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        int bitCount = 0;
        int n = num;
        while (n > 0) {
            bitCount++;
            n = n >> 1;
        }
        int all_bits_set = pow(2, bitCount) - 1;
        return num ^ all_bits_set;
    }
};
// @lc code=end

