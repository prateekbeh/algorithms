/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int ws = 0;
        unordered_map<int,int> ump;
        int min_length = 123456789;
        int len = s.length();
        int matched = 0;
        int subStrStart = 0;
       for(auto chr:t){
           ump[chr]++;
       }
       for(int we = 0; we < len ; we++){
           char right = s[we];
           if(ump.find(right) != ump.end()){
               ump[right]--;
               if(ump[right] >= 0){
                   // >= 0 because if it were previously 1 it would become 0.
                   matched++;
               }
           }
           while(matched == t.length()){
               // now we shrink the window.
               if(min_length > we - ws + 1){
                   min_length = we - ws + 1;
                   subStrStart = ws;
               }
                char left = s[ws++];
               if(ump.find(left) != ump.end()){
                   if(ump[left] == 0){
                       matched--;
                   }
                   //after decrementing the matched length we will try 
               //to find the same char from right
               //from starting of the loop.
                   ump[left]++;
               }
               
               
           }

        }
        return min_length > s.length() ? "" :  s.substr(subStrStart, min_length);       
    }
    
};
// @lc code=end

