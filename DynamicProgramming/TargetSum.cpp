// We can consider the problem count number of subsets having difference equal to target
// S2 - S1 = Target
// S2 + S1 = sum(nums)
// S2 = (Target + sum(nums))/2
int countSubsets(int sum, vector <int> &nums) {

    int n = nums.size();
    int dp[n+1][sum+1];
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=sum; j++) {
            if(i == 0 and j != 0)// Except first col
                dp[i][j] = 0;
            else if(i == 0 and j == 0)
                dp[i][j] = 1;
            else if(nums[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
        }
    }
    return dp[n][sum];
}
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            sum += nums[i];
        }
        if((target + sum)%2 != 0) {
            return 0;
        }
        int subsetSum = (target + sum)/2;
        int ans = countSubsets(subsetSum, nums);
        return ans;
    }
};
