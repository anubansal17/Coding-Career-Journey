// Approach 1 - 2D dp
class Solution {
    int knapsack(vector <int>wt, int sum, int n) {
        int tp[n+1][sum+1];
        for (int i=0; i<=n; i++) {
            for(int j=0; j<=sum; j++) {
                // If number of coins are zero, we would require infinite number of
                // coins to make it to the reqd sum
                if(i == 0) {
                    tp[i][j] = INT_MAX-1;
                } 
                // If sum reqd is zero and number of coins given is non zero
                else if(sum == 0) {
                    tp[i][j] = 0;
                }
                // Initialising second row except first column
                else if(i == 1){
                    // Number of coins = 1 and sum is non zero
                    // CHeck if the required some is possible with given coin or not
                    // If possible
                    if(j%wt[0] == 0) {
                        tp[i][j] = j/wt[0];
                    }
                    // Else
                    else {
                        tp[i][j] = INT_MAX-1;
                    }
                }
                // For rest of the rows
                else if(wt[i-1] <= j) {
                    // As we are adding 1 here, to avoid overflow we considered INT_MAX-1
                    tp[i][j] = min(tp[i][j-wt[i-1]]+1, tp[i-1][j]);
                } else {
                    tp[i][j] = tp[i-1][j];
                }
            }
        }
        //cout<<tp[n][sum];
        return tp[n][sum];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = -1;
        ans = knapsack(coins, amount, coins.size());
        if(ans == INT_MAX-1 || ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};

// Approach 2: Coin Change - 1D dp
class Solution {
public:
    int dp[10001];
    int minCoins(vector<int> &coins, int amt, int n) {
        if(amt == 0) {
            return 0;
        }
        int ans = INT_MAX;
        if(dp[amt] != -1)
            return dp[amt];
        for(int i=0; i<n; i++) {
            if(coins[i] <= amt){
                int temp;
                if(dp[amt - coins[i]] != -1)
                    temp = dp[amt - coins[i]];
                else
                    temp = minCoins(coins, amt - coins[i], n);
                if(temp != INT_MAX and temp + 1 < ans) {
                    ans = temp + 1;
                }
            }
        }
        return dp[amt] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        memset(dp, -1, sizeof(dp));
        int ans = minCoins(coins, amount, size);
        return ans != INT_MAX ? ans : -1;
    }
};
