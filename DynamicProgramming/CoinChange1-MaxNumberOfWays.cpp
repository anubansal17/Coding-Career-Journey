// Memorization solution
class Solution {
     int dp[501][5001];
    int knapsack(vector<int> val, int n, int sum) {
        // base condition - if there are no coins or sum required is zero
        if (sum == 0) {
            return dp[n][sum] = 1;
        } else if (n == 0) {
            return dp[n][sum] =  0;
        }
        if(dp[n][sum] != -1) {
            return dp[n][sum];
        }
        // If valus of coin is greater than sum reqd
        else if (val[n-1] > sum) {
            // Consider the answer as it was in the previous result 
            return dp[n][sum] = knapsack(val, n-1, sum);
        } 
        // If the value of the coin is less than or equal to the reqd sum - add the number of combinations by considering this element to the previous result
        else {
            return dp[n][sum] =  (knapsack(val, n, sum - val[n-1]) + knapsack(val, n-1, sum));
        }
    }
public:
    // Output - nunber of possible combinations making a sum as S
    // More of a count number of subsets problem
    int change(int amount, vector<int>& coins) {
        int ans;
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        ans = knapsack(coins, n, amount);
        return ans;
    }
};
