// Given Intervals are sorted or not
/*
Approach 1: Brute Force, T.C - O(n^2)
- Sort the intervals - O(nlogn)
- For every interval, do a linear scan to check for all its merging intervals and then merge them and add them in other data structure - O(n^2)
- Move to the next interval, check if this lies in the interval just added in the other data structure

Approach 2: 
*/
// Implementation of Approach 1
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        if(n == 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        for (int i=0; i<n; i++) {
            // If the interval already lies in the merged inetrval
            int currentSize = ans.size();
            if(currentSize > 0 and intervals[i][0] <= ans[currentSize-1][1]) {
                continue;
            }
            int mergeIndex = i;
            for (int j=i+1; j<n; j++) {
            // If end of any interval is greater than or equal to start of next                      interval, it can be merged
            if(intervals[mergeIndex][1] >= intervals[j][0] and intervals[mergeIndex][1] < intervals[j][1]) {
                mergeIndex = j;
                }
            }
            ans.push_back({intervals[i][0], intervals[mergeIndex][1]});
        }
        // Check if last interval is merged or not
        if(n > 0 and intervals[n-1][0] > ans[ans.size()-1][1]) {
            ans.push_back({intervals[n-1][0], intervals[n-1][1]});
        }
        return ans;
    }
};
