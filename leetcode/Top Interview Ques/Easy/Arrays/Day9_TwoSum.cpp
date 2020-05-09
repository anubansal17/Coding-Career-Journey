// Problem: https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/
// We can use binary search for this, to find out target - i element.
// If it is present in the array we can return its index otherwise return -1
class Solution {
    int search(int num, vector <int> arr, int ignoreIndex){
        int l = 0;
        int r = arr.size() - 1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if((arr[mid] == num) and (mid != ignoreIndex)){
                return mid;
            }else if(num > arr[mid]){
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        return -1;     
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector <int> ans;
        vector <int> nums1 = nums;
        sort(nums1.begin(), nums1.end());
        int secondIndex = -1;
        int firstIndex = -1;
        for (int i=0; i<n; i++){
            secondIndex = search(target - nums1[i], nums1, i);
            cout<<i<<secondIndex;
            if(secondIndex != -1){
                firstIndex = i;
                break;
            }
        }
        int secNum = nums1[secondIndex];
        int firNum = nums1[firstIndex];
        for (int i=0; i<n; i++){
            if(nums[i] == secNum){
                ans.push_back(i);
            }
            else if(nums[i] == firNum){
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
