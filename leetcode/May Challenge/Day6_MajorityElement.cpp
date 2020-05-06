//https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3321/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int curNum = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] == curNum){
                count ++;
            } else{
                if(count == 0){
                    curNum = nums[i];
                    count = 1;
                } else{
                    count --;
                }
            }
        }
        return curNum;
    }
};
