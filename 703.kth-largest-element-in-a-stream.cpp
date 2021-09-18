/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest {
public:
    struct numCompare {
        bool operator()(const int &x, const int &y) { return x > y; }
    };

    priority_queue<int, vector<int>, numCompare> minHeap;
    const int k;
    KthLargest(int k, vector<int>& nums) : k(k){
        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if ((int)minHeap.size() > this->k) {
            minHeap.pop();
        }

        
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

