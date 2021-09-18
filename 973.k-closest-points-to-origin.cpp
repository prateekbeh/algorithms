/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start

class cmp{
    public:
        bool operator()(const vector<int> &x, const vector<int> &y){
            return x[0]*x[0] + x[1]*x[1] < y[0]*y[0] + y[1]*y[1];
        }
};
class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<vector<int>,vector<vector<int>> ,cmp> pq;
        for(int i = 0 ; i < k ; i++){
            pq.push(points[i]);
        }
        //cout<< pq.top()<<endl;
        
        for(int i = k ; i < points.size() ; i++){
            vector<int> tp = pq.top();
            int dist = tp[0]*tp[0] + tp[1]*tp[1];
            if( points[i][0] * points[i][0] + points[i][1]*points[i][1] < dist){
                pq.pop();
                pq.push(points[i]);
            }
        }
        
        
        vector<vector<int> > res;
        
        while(!pq.empty()){
            vector<int> elm = pq.top();
            res.push_back(elm);
            pq.pop();
        }
        
        return res;

    }
};
// @lc code=end

