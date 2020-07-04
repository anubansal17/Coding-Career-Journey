// https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3379/
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector <int> ans(8,0);
        N = N%14?N%14:14;
        for (int i=0; i<N; i++) {
            for (int j=1; j<7; j++) {
                if(cells[j-1] == cells[j+1]) {
                    ans[j] = 1;
                } else{
                    ans[j] = 0;
                }
                
            }
            cells = ans;
        }
        return ans;
    }
};
