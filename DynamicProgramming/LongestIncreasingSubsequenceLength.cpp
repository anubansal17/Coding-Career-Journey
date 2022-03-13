// N^2 soln
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int dp[2501];
//         int n = nums.size();
//         dp[0] = 1;
//         int maxm = 1;
//         for (int i=1; i<n; i++) {
//             dp[i] = 1;
//             for (int j=0; j<i; j++) {
//                 if(nums[j] < nums[i])
//                     dp[i] = max(dp[j]+1, dp[i]);
//             }
//             cout<<dp[i];
//             maxm = max(dp[i], maxm);
//         }
//         return maxm;
//     }
// };

// nlogn soln
class Solution {
    int search(vector<int> space, int num) {
        int size = space.size();
        int start = 0;
        int end = size-1;
        int mid = start;
        while(start<end) {
            mid = start + (end-start)/2;
            if(space[mid]<num)
                start = mid+1;
            else if(space[mid]>num)
                end = mid;
            else
                return mid;
        }
        return end;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <int> lis;
        lis.push_back(nums[0]);
        for(int i=1; i<n; i++) {
            // If last element in the lis is lesser than current element
            int size = lis.size();
            if(lis[size-1] < nums[i])
                lis.push_back(nums[i]);
            // binary search for finding immediate next greater element and replacing it with current element
            else {
                int index = search(lis, nums[i]);
                lis[index] = nums[i];
            }
        }
        return lis.size();
    }
};
