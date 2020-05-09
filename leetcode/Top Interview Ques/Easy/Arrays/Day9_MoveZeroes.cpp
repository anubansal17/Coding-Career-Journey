// Problem: https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/567/
// Tip : Don't decrement i in for loop and variable which contains size of vector when you are using clear function, most often mistake
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i=0; i<nums.size();){
            if(nums[i] == 0){
                nums.erase(nums.begin() + i);
                count ++;
            }else{
                 i++;
            }
        }
        while(count>0){
            nums.push_back(0);
            count --;
        }
    }
};
