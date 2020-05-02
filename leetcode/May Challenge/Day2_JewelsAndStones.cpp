//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map <char, int> stones;
        map <char, int>::iterator it;
        int n = S.length();
        int ans = 0;
        //Making map for counting each type of stones
        for (int i=0; i<n; i++){
            if(stones.find(S[i]) == stones.end()){
                stones.insert({S[i],1});
            }else{
                it = stones.find(S[i]);
                it->second ++;
            }
        }
        int m = J.length();
       for (int i=0; i<m; i++){
        it = stones.find(J[i]) ;
           if(it != stones.end()){
               ans += it->second;
           }
       }
        return ans;
    }
};
