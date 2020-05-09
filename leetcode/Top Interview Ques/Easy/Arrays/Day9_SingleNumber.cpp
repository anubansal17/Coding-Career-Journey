// Problem: https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/549/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        for (int i=1; i<n; i++){
            ans = nums[i]^ans;
        }
        return ans;
    }
};
