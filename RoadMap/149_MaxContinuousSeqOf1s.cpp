class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0;
        int start = 0;
        int ans = 0;
        int end = nums.size()-1;
        while(start <= end){
            if(nums[start] == 1) {
                maxLen ++;
            } else{
                maxLen = 0;
            }
            ans = max(maxLen, ans);
            start++;
        }
        return ans;
    }
};
