// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3341/
class Solution {
// Approach: Replace 0 with -1 and keep adding elements one by one
// Add the sum at each iteration to a map  (initialise map with one element as sum 0 and index -1) and keep track of index of its first occurence
// Initialise max with 0 and on second occurence of any sum, say at i then check i - map[sum]
// If it is greater than max then assign it to max
// return max
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        unordered_map <int, int> mp;
        mp.insert({0, -1});
        int sum = 0;
        for (int i=0; i<n; i++) {
            if(nums[i] == 0) {
                sum += -1;
                }
            else {
                sum += nums[i];
            }
            if(mp.find(sum) == mp.end()) {
                    mp.insert({sum, i});
            }else {
                if((i - mp[sum]) > maxLen) {
                    maxLen = i - mp[sum];
                }
            }
        }
        return maxLen;
    }
};
