// Given Intervals are sorted or not
/*
Approach 1: Brute Force, T.C - O(n^2)
- Sort the intervals - O(nlogn)
- For every interval, do a linear scan to check for all its merging intervals and then merge them and add them in other data structure - O(n^2)
- Move to the next interval, check if this lies in the interval just added in the other data structure

Approach 2: T.C - O(nlogn)
- Sort the complete 2d vector
- Initialise the current interval pair
- Iterate over the given vector and check if it merges with the current interval pair
- If it merges than simply change this pair's ending interval if it is lesser
- else add the current pair in the answer vector and replace the pair with current element pair in the vector
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
            // If end of any interval is greater than or equal to start of next interval, it can be merged
            // We will change the second value of interval only if the new interval that is to be merged has greater value than current one
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
// Implementation of Approach 2
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
   
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<int> cur = intervals[0];
        vector<vector<int>> ans;
        for (int i=1; i<n; i++) {
            if(intervals[i][0] <= cur[1]){
                cur[0] = min(cur[0], intervals[i][0]);
                cur[1] = max(cur[1], intervals[i][1]);
            } else{
                ans.push_back(cur);
                cur = intervals[i];
            }
        }
        ans.push_back(cur);
        return ans;
    }
};
