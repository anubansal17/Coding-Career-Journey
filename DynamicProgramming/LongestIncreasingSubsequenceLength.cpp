// Time complexity - O(n^2)
class Solution {
    int LIS(vector<int> nums, int n) {
        int tp[n];
        for (int i=0; i<n; i++) 
            tp[i] = 1;
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                if(nums[j] < nums[i]) {
                    tp[i] = max(tp[i], tp[j]+1);
                }
            }
        }
        int max = INT_MIN;
        for (int i=0; i<n; i++) {
            cout<<tp[i];
            if(max < tp[i]) {
                max = tp[i];
            }
        }
        return max;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int len;
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        len = LIS(nums,n);
        return len;
    }
};
