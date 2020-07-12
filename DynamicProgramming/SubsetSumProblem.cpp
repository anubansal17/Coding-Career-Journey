class Solution {
    // Basically, the crux of the problem is to find if any subset exists whose sum is equal to sum of array/2
    int knapsack(vector<int> wt, int w, int n){
    int tp[n+2][w+2];
    // Iterative approach - top down
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<w+1; j++) {
            // Base Condition - If number of items is 0 and sum reqd != 0
            if(i == 0 and j != 0){
                tp[i][j] = 0;
            }
            // If reqd sum is 0
             else if (j == 0) {
                tp[i][j] = 1;
            }
             // If weight of cur item is greater than capacity, we won't choose this item
            else if(wt[i-1] > j){
                tp[i][j] = tp[i-1][j];
                 
            } else {
                // We will take or of two cases: If we are choosing current element or not
                tp[i][j] = tp[i-1][j-wt[i-1]] || tp[i-1][j]; 
            }
        }
    }
    return tp[n][w];
}
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            sum += nums[i];
        }
        // If sum is odd, then it can't be divided into equal halves
        if(sum %2 != 0) {
            return 0;
        }
        sum = sum/2;
        bool ans = knapsack(nums, sum, n);
        return ans;
    }
};
