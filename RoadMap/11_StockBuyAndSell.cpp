/*
Approach 1: Brute Force: T.C- O(n^2), S.C- O(1)
- For each element check for the highest greater element possible at the right side
Approach 2: T.C- O(n), S.C- O(1)
- Keep track of minimum at the left side
- Calculate the profit while scanning the array from left to right
- Initialise profit as 0, If the profit is greater than change it and if you find any other number lesser than minimum number so far, then update the minimum number
- Atlast, profit at the end will be our answer
Approach 3: T.C - O(n), S.C - O(1)
- Start from ending
- Keep track of maxProfit so far and maxPrice so far
OR
- Start from start
- Keep track of maxProfit so far and minPrice so far
*/
// Approach 2: Code
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
        if(n == 0) {
            return 0;
        }
        int ans = 0;
        vector <int> maxRight(n);
        int maxm = prices[n-1];
        maxRight[n-1] = maxm;
        for (int i=n-2; i>= 0; i--) {
            maxm = max(maxm, prices[i]);
            maxRight[i] = maxm;
        }
        for(int i=0; i<n ; i++) {
            ans = max(ans, maxRight[i] -  prices[i]);
        }
        return ans;
    }
};

// Approach 3: Implementation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
        int maxPrice = INT_MIN;
        int maxProfit = 0;
        for (int i=n-1; i>=0; i--) {
                maxPrice = max(prices[i], maxPrice);
                maxProfit = max(maxPrice - prices[i], maxProfit);
        }
        return maxProfit;
    }
};
