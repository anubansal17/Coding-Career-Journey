// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3333/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
     
        vector <int> arr1(26, 0);
        vector <int> arr2(26, 0);
        int n1 = s1.length();
        int n2 = s2.length();
        //If length of s2< length of s1
        if(n2<n1){
            return false;
        }
        for (int i=0; i<n1; i++){
            arr1[s1[i]-'a'] ++;
        }
        for(int i=0; i<n1; i++){
            arr2[s2[i]-'a'] ++;
        }
        if(arr1 == arr2){
            return true;
        }
        for(int i=n1; i<n2;i++){
           
            arr2[s2[i]-'a']++;
            arr2[s2[i-n1]-'a']--;
            if(arr1 == arr2){
                return true;
            }
        }
        return false;
    }
};
