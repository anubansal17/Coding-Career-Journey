class Solution {
    // Approach:
    // A - A + 1 = 1
    // B - A + 1 = 2
    // scan from left to right
    // char(i) - A + 1 + 26^i
public:
    int titleToNumber(string s) {
        int n = s.length();
        int ans = 0;
        for (int i=n-1; i>=0; i--) {
            ans += (s[i] - 'A' + 1)* pow(26, n-i-1);
        }
        return ans;
    }
};
