//https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3377/
class Solution {
public:
    int arrangeCoins(int n) {
        int k = 1;
        int count = 0;
        while (n-k >= 0) {
            n = n - k;
            count ++;
            k ++;
        }
        return count;
    }
};
