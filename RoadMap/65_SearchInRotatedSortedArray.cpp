class Solution {
public:
    int findRotation(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        while(start < end) {
            int mid = start+(end-start)/2;
         if(nums[mid] > nums[end])
                start = mid+1;
            else
                end = mid;
        }
        return end;
    }
    int search(vector<int>& nums, int target) {
        int k = findRotation(nums);
        cout<<k;
        int start = 0;
        int n = nums.size();
        int end = nums.size()-1;
        while(start <= end) {
            int mid = start+(end-start)/2;
            if(nums[(mid+k)%n] == target)
                return (mid+k)%n;
            if(nums[(mid+k)%n] > target)
                end = mid - 1;
            else
                start = mid+1;
        }
        return -1;
    }
};
