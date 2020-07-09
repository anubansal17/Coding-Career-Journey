// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3384/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       int n = nums.size();
        sort(nums.begin(), nums.end());
        vector <vector<int> > ans;
        set <vector <int> > stAns;
        for (int i=0; i<n; i++) {
            int cur = nums[i];
            int left = i+1, right = n-1;
            while(left < right){
                if(nums[left]+nums[right]+cur == 0){
                    stAns.insert({nums[left++], cur, nums[right--]});
                }
                else if(nums[left] + nums[right] + cur > 0) {
                    right --;
                } else{
                    left++;
                }
            }
        }
        for (vector v : stAns){
            ans.push_back(v);
        }
        return ans;
    }
};
