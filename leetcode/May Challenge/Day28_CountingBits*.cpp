// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3343/
class Solution {
public:
    vector<int> countBits(int num) 
    {
        vector<int> v(num+1, 0);
        for(int i=1;i<= num; i++) v[i]=v[i/2]+i%2;
        return v;
    }
};
