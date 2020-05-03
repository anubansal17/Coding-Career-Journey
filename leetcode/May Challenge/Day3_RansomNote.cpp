// Problem: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map <char, int> mp;
        map <char, int>::iterator it;
        int n = magazine.length();
        for (int i=0; i<n; i++){
            if(mp.find(magazine[i]) == mp.end()){
                mp.insert({magazine[i], 1});
            }else{
               it = mp.find(magazine[i]);
                it->second ++;
            }
        }
        int m = ransomNote.length();
        for (int i=0; i<m; i++){
            it = mp.find(ransomNote[i]);
            if(it == mp.end() or it->second == 0){
                return false;
            }else{
                it->second --;
            }
        }
        return true;
    }
};
