/*
Most Optimized Approach: Use Moore's Voting algo
- Atmost there can be 2 majority elements and atleast there can be 0
- Use this idea to solve this problem
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        int majEle1;
        int majEle2;
        for (int i=0; i<n; i++){
            if(nums[i] == majEle1) {
                count1++;
            } else if(nums[i] == majEle2) {
                count2++;
            } else if (count1 == 0) {
                count1 = 1;
                majEle1 = nums[i];
            } else if(count2 == 0) {
                count2 = 1;
                majEle2 = nums[i];
            } else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if(num == majEle1) {
                count1++;
            } else if(num == majEle2) {
                count2++;
            }
        }
        vector<int> ans;
        if(count1>n/3)
            ans.push_back(majEle1);
        if(count2>n/3)
            ans.push_back(majEle2);
        return ans;
    }
};
