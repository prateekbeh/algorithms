/*
 * @lc app=leetcode id=457 lang=cpp
 *
 * [457] Circular Array Loop
 */

// @lc code=start
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int len = nums.size();

        for(int i = 0 ; i < len  ; i++){
            //for evert element we check if the elem
            // will form the cycle of not.
            bool isForward = nums[i] >= 0;
            int slow = i;
            int fast = i;
            do{
                //cout << "1 slow = " << slow << "  fast = " << fast << endl;
                slow = findindex(nums , isForward , slow);
                //cout<< "slow = " << slow << endl;
                fast = findindex(nums , isForward , fast);
                //cout<< "fast = " << fast << endl;
                if(fast != -1){
                    fast = findindex(nums, isForward , fast);
                    //cout<< "inside fast = " << fast << endl;
                }
                //cout << "slow = " << slow << "  fast = " << fast << endl;
            }while(slow != -1 && fast != -1 && slow != fast);  
            if(slow != -1 && slow == fast){
                return true;
            }
        }
        
        return false;
    }
    int findindex(vector<int> &arr , bool isForward , int curr){
        bool direction = arr[curr] >= 0;
        if(isForward != direction){
            return -1;
        }

        int nextIndex = (arr.size() + curr + arr[curr]) % arr.size();
        // cout<<(curr + arr[curr]) << "="<< arr.size() << "=" << nextIndex <<endl;
        if(nextIndex < 0){
            nextIndex += arr.size();
        }
        if(nextIndex == curr){
            return nextIndex = -1;
        }
        return nextIndex;
    }
};
// @lc code=end

