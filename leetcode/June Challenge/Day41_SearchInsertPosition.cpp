// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3356/
int findIndex(vector <int> &nums, int left, int right, int target) {
    int ans = 0;
    int mid;
    while(left <= right) {
        mid = left + (right-left)/2;
        if(nums[mid] == target){
            return mid;
        } else if(nums[mid] < target){
            ans = mid + 1;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans;
        ans = findIndex(nums, 0, nums.size()-1, target);
        return ans;
    }
};
