// Problem: https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return 1;
        }
        for (auto i=nums.begin()+1; i!=nums.end(); ){
            if(*i == *(i-1)){
               nums.erase(i-1);
                 
           }else{
                i++;
            }
        }
    return nums.size();
    }
    
};
