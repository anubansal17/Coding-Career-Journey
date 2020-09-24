/*
Approach 1: Brute force - run 3 loops T.C - O(n^3) roughly
for (i=0 to n)
    for(j = i to n)
        for(k=i to j)

Approach 2: Remove the inner k for loop, keep on adding sum in second for loop,T.C-O(n^2)
Approach 3: Kadane's Algo, T.C - O(n)
Initialise sum = 0;
max_sum = arr[0];
traverse the array and add element to sum
if sum > max_sum then consider the element and max_sum = sum
else do nothing
if sum < 0, make sum = 0 (Carrying a negative sum will not be of any use to us)
return max_sum as answer

*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max_sum = nums[0];
        int n = nums.size();
        for (int i=0; i<n; i++) {
            sum += nums[i];
            if(sum > max_sum) {
                max_sum = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return max_sum;
    }
};
