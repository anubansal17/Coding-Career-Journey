// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/578/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       //M1 - Using Sorting 
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i=1; i<n; i++){
            if(nums[i] == nums[i-1]){
                return true;
            }
        }
        return false;
    }
};
