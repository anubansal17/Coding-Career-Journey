// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3332/
//M1 - Brute force Approach - Time Complexity: O(n^2logn)
// Sort given pattern string
/*for (int i=0; i<ns-np+1; i++){
            string curString = s.substr(i,np);
            sort(curString.begin(), curString.end());
            if(curString == p){
                ans.push_back(i);
            }
    }
*/
// M2 - Keeping the count of occurences of each character present in string and then comparing the array containing these count for given pattern string and window string in s
//  Time Complexity: O(n)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
     // sort(p.begin(), p.end());
        vector <int> ans;
        int np = p.size();
        int ns = s.size();
        
        // corner case : if size of reqd pattern string is more than the size of the string s
        if(ns < np){
            return ans;
        }
        if(np==0){
            return ans;
        }
        
       
        // As we have only 26 characters, given in problem
        vector <int> pattern(26, 0);
        vector <int> window(26, 0);
        for (int i=0; i<np; i++){
           pattern[p[i] - 'a'] ++;
        }
        // for first np sized window in s
        for (int i=0; i<np; i++){
            window[s[i] - 'a']++;
        }
        if(window == pattern){
            ans.push_back(0);
        }
        for (int i=np; i<ns; i++){
 
            // adding the occurence of new element in the window
            window[s[i] - 'a'] ++;
            // removing the occurence of first element present in the window
            window [s[i - np] - 'a']--;
            // considering the starting index of window
            if(window == pattern){
                ans.push_back(i - np + 1);
            }
        }
        return ans;
    }
};
