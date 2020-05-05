// Problem: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3320/
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        unordered_map <char,int> count;
        unordered_map <char,int> :: iterator it;
        for(int i=0; i<n; i++){
            if(count.find(s[i]) == count.end()){
                count.insert({s[i], 1});
            }
            else{
               it = count.find(s[i]);
                it->second ++;
            }
        }
        for (int i=0; i<n; i++){
            if(count.find(s[i])->second == 1){
                return i;
            }
        }
        return -1;
    }
};
