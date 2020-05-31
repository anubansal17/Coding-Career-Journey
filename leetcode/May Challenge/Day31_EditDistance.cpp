// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3346/
// Approach - DP
class Solution {
public:
    int minDistance(string word1, string word2) {
      
        int n1 = word1.size();
        int n2 = word2.size();
        vector <vector <int>> dp(n1+1);
        for (int i=0; i<=n1; i++) {
            dp[i] = vector<int> (n2+1,0);
        }
        for(int i=0; i<=n1; i++) {
            for (int j=0; j<=n2; j++) {
                if(i == 0){
                    dp[0][j] = j;
                } else if (j == 0) {
                    dp[i][0] = i;
                } else if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else{
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j],dp[i][j-1]}) +1;
                }
            }
        }
        for (int i=0; i<=n1; i++) {
            for (int j=0; j<=n2; j++) {
                cout<<dp[i][j];
            }
            cout<<endl;
        }
        return dp[n1][n2];
    }
};
