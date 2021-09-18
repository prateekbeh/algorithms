/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int num) {
        int slow = num;
        int fast = num;
        cout<<slow << " = "<< fast;
        do{
            slow = findss(slow);
            fast = findss(findss(fast));
            cout<<"slow = "<< slow<<" fast="<<fast;
        }while(slow != fast);
        return slow == 1;
    }
    int findss(int num){
        int sum = 0;
        int dig = 0;
        while(num > 0){
            dig = num%10;
            sum += dig*dig;
            num /= 10;
        }
        return sum;
    }
};
// @lc code=end

