// Memorization approach - gave time limit exceeded
class Solution {
    int tp[1001][1001];
    
    int LCS(string s1, string s2, int n, int m) {
        // Base condition
        if(n == 0 or m == 0)
            return tp[n][m] = 0;
        if(tp[n][m] != -1) {
            return tp[n][m];
        }
        // If elements at current indexes of both the strings are equal
        else if(s1[n-1] == s2[m-1]) {
            return tp[n][m] = 1+LCS(s1,s2, n-1, m-1);
        } else {
            return tp[n][m] = max(LCS(s1, s2, n, m-1), LCS(s1, s2, n-1, m));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int ans;
        int n = text1.length();
        int m = text2.length();
        memset(tp, -1, sizeof(tp));
        ans = LCS(text1, text2, n, m);
        return ans;
    }
};

//Tabulation Method
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
    int longestCommonSubsequence(string text1, string text2) {
        int ans;
        int n = text1.length();
        int m = text2.length();
        ans = LCS(text1, text2, n, m);
        return ans;
    }
};
