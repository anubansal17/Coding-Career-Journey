class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
      // 1 2 3
      // 4 5 6
      // 7 8 9
        // 5  7  9
        // 12 15 18
        // 11 13 15
        int m = mat.size();
        int n = mat[0].size();
        vector <vector<int>> col(m, vector<int> (n, 0));
       vector <vector<int>> dp(m, vector<int> (n, 0));
        // Col values for first row
        for (int i=0; i<n; i++) {
            for (int j=0; j <= k and j < m; j++) {
                col[0][i] += mat[j][i];
            }
        }
        for (int i=1; i<m; i++) {
            for (int j=0; j<n; j++) {
                col[i][j] += col[i-1][j];
                if(i+k < m) 
                    col[i][j] += mat[i+k][j];
                if(i-k-1 >= 0) 
                    col[i][j] -=  mat[i-k-1][j];
            }
        }
        for (int j=0; j<m; j++) {
         for (int i=0; i<=k and i<n; i++) {
            dp[j][0] += col[j][i];
            }   
        }
        for (int i=0; i<m; i++) {
            for (int j=1; j<n; j++) {
                if(j-1 >= 0)
                    dp[i][j] += dp[i][j-1];
                if(j+k < n) 
                    dp[i][j] += col[i][j+k];
                if(j-k-1 >= 0) 
                    dp[i][j] -=  col[i][j-k-1];
            }
        }
        return dp;
    }
};
