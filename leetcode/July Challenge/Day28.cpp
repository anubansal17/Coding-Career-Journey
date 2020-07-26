// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3401/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        int right = n-1;
        if(nums[left]<nums[right]) {
            return nums[left];
        }
        int ans;
        while (left < right) {
            int mid = (left + right) / 2; 
            // To deal with duplicates, we are decrementing the right pointer by one if it turns out to 
            // be equal to mid element
		    if (nums[mid] == nums[right]) 
			    right--; 
		    else if(nums[mid] > nums[right]) 
			    left = mid + 1; 
		    else {
                  right = mid;
            }
			  
        }
        return nums[right];
    }
};
