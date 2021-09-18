/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0 , j = 0;
        while( i < firstList.size() && j < secondList.size()){
            //check if the one of the startime of the array lies between the other interval.
            if(firstList[i][0] >= secondList[j][0] && firstList[i][0] <= secondList[j][1] || 
                secondList[j][0] >= firstList[i][0] && secondList[j][0] <= firstList[i][1]){
                    res.push_back({max(firstList[i][0],secondList[j][0] ) , min(firstList[i][1],secondList[j][1])});
                }
            if(firstList[i][1] < secondList[j][1]){
                i++;
            }else{
                j++;
            }
        }
        return res;
    }
};
// @lc code=end

