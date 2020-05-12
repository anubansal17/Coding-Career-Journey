// Problem: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/
// Solution:
// Time Complexity : O(n)
// Space Complexity : O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = nums[0];
        int n = nums.size();
        for (int i=1; i<n; i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};
