// Approach 1: Simple one
class Solution {
public:
bool isSubsequence(string s, string t) {
        
        int i,j,n,m;
        n = s.size();
        m = t.size();
        i=j=0;
        
        while(i<n and j<m)
        {
            if(s[i]==t[j])       // increment i pointer as we have found a match
                i++;
            j++;
        }
        
        return i==n;    // return whether we have found all the matches or not
    }
};

// Approach 2: LCS based
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
    bool isSubsequence(string s, string t) {
       // s will be a subsequence of t only if LCS of s and t is equal to s
        int n = s.length();
        int m = t.length();
        int len = LCS(s, t, n, m);
        if(len == n) {
            return 1;
        }
        return 0;
    }
};
