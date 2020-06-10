// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3355/
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
