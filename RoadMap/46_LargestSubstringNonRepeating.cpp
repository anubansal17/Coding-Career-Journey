// abba
// 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[256];
        memset(arr, -1, sizeof(arr));
        int n = s.size();
        int curLen = 0, maxLen = 0;
        for (int i=0; i<n; i++) {
            if(arr[s[i]] == -1){
                curLen++;
                arr[s[i]] = i;
            } else{
                if(curLen < (i  - arr[s[i]])){
                    curLen++;
                    arr[s[i]] = i;
                }else
                    curLen = i - arr[s[i]];
                    arr[s[i]] = i;
            }
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};
