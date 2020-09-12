// Problem: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3448/
class Solution {
public:
    vector<int> partitionLabels(string S) {
      int n = S.size();
        map <char, int> mp;
        vector <int> ans;
        // Preparing the map for last of all chars
        for(int i=0; i<n; i++) {
            mp[S[i]] = i;
        }
        int max_index = -1;
        int start_index = 0;
        // Iterate over the string
        for(int i=0; i<n; i++) {
            if(max_index < mp[S[i]]) {
                max_index = mp[S[i]];
            }
        if(i == max_index) {
                ans.push_back(max_index-start_index+1);
                start_index = max_index+1;
            }
        }
        return ans;
}
};
