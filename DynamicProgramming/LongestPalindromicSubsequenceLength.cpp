class Solution {
    int LCS(string s1, string s2, int n, int m) {
        int tp[n+1][m+1];
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=m; j++) {
               // Base condition
                if(i == 0 or j == 0)
                    tp[i][j] = 0;
                // If elements at current indexes of both the strings are equal
                else if(s1[i-1] == s2[j-1]) {
                    tp[i][j] = 1+tp[i-1][j-1];
                } else {
                    tp[i][j] = max(tp[i][j-1], tp[i-1][j]);
                } 
            }
        }
        return tp[n][m];
    }
public:
    int longestPalindromeSubseq(string s) {
        // It's a variant of LCS - we just need 2nd string
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.length();
        // LCS of both s1 and s2 would be longest palindromic subsequence possuble
        int ans = LCS(s1, s2, n, n);
        return ans;
    }
};
