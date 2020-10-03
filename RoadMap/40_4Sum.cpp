/*
Approach 1: Three loops + Binary Search T.C - O(n^3Logn(n)), S.C- O(1)
Approach 2: Two loops + two pointers, T.C - O(n^3), S.C- O(1)
- Sort the vector given
- for i= 0 to n-1
-   for j = i+1 to n-1
-       left = j+1
-       right = n-1
-       target2 = target - nums[i] - nums[j]
-       while(left < right){
-       if(nums[left]+nums[right] < target2) left++;
-       else if(nums[left] + nums[right] > target2) right--;
-       else {
-       add these elements as quadruplet to answer
-       increment the left to next distinct element
-       increment the right to next distinct element
-   }
-       }
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
    }
};
