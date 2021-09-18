class valueCompare{
    public:
        bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
            return y.second > x.second;
        }
};
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> charFrequencyMap;
        for (char chr : str) {
            charFrequencyMap[chr]++;
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;

        // add all characters to the max heap
        for (auto entry : charFrequencyMap) {
            maxHeap.push(entry);
        }
        pair<char, int> previousEntry(-1, -1);
        string resultString = "";
        while (!maxHeap.empty()) {
            pair<char, int> currentEntry = maxHeap.top();
            maxHeap.pop();
            // add the previous entry back in the heap if its frequency is greater than zero
            if (previousEntry.second > 0) {
                maxHeap.push(previousEntry);
            }
            // append the current character to the result string and decrement its count
            resultString += currentEntry.first;
            currentEntry.second--;
            previousEntry = currentEntry;
        }

        // if we were successful in appending all the characters to the result string, return it
        return resultString.length() == str.length() ? resultString : "";
    }
};
