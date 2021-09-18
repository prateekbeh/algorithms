/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start

class compare{
    public:
        bool operator()(const pair<int,int> &a , const pair<int,int> &b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first > b.first;
        }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index = binarySearch(arr,x);
        int low = max(0,index - k);
        int high = min((int)arr.size()-1, index + k);
        
        priority_queue<pair<int,int> , vector<pair<int,int>>, compare> minheap;

        for(int i = low ; i <= high ; i++){
            minheap.push(make_pair(abs(arr[i] - x),arr[i]));
        }
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(minheap.top().second);
            
            minheap.pop();
        }
        sort(result.begin(), result.end());
        return result;

    }
    int binarySearch(vector<int> &arr , int key){
        int end = arr.size() - 1;
        int start = 0;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] > key){
                //lower half;
                end = mid - 1;
            }else if( arr[mid] < key){
                start = mid + 1;
            }
            else{
                return mid;
            }
        }
        if(start > 0){
            return start - 1;
        }
        return start;
    }
};
// @lc code=end

