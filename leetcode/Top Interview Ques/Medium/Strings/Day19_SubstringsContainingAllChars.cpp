// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        // We are using unordered map, so that insertion and delteion can be done in           //O(n)
        int leftPt = 0;
        unordered_map <char, int> mp;
        int ans = 0;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
            while (mp.size() == 3){
                // All the strings at the right side will be considered in the answer
                ans += n-i;
                char leftChar = s[leftPt];
                leftPt++;
                mp[leftChar]--;
                if(mp[leftChar]==0){
                    mp.erase(leftChar);
                }
            }
        }
        return ans;
    }
};
