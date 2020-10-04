/*
Approach 1: Generate all subarrays and then calculate its product, T.C - O(n^3)
Approach 2: By storing the maxProduct and minProduct so far, T.C - O(n), S.C- O(1)
- At every iteration, we will be having 3 choices out of which we gonna decide maxProd so far and min prod so far
- initialise ans, choice1 and choice2 as arr[0]
- for each iteration from 1 to n-1
- choice1 = maxProd*arr[i];
- choice2 = minProd*arr[i];
- minProd = min(min(choice1, choice2),arr[i]);
- maxProd = max(max(choice1, choice2, arr[i]));
- ans = max(ans, maxProd);

*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int maxProd = nums[0];
    int minProd = nums[0];
    int ans = nums[0];
    int choice1, choice2;
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        choice1 = maxProd*nums[i];
        choice2 = minProd*nums[i];
        maxProd = max(max(choice1, choice2), nums[i]);
        minProd = min(min(choice1, choice2), nums[i]);
        ans = max(ans, maxProd);
    }
    return ans;
    }
};
