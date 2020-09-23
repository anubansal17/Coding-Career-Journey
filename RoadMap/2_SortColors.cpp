/*
Approach 1: Count number of 0, 1 and 2 (O(n) but 2 passes - T.C and O(1) - S.C)
Approach 2: Similar to Dutch National Flag Algo - O(n) and 1 pass - T.C
- Traverse the array from both ends - 3 ptrs: low, mid, high
- Initialize low = 0, mid = 0 and high = n-1
- We will modify the aaray such that all the elements at the left side of low are 0
- and all the elements at the right side of high are all 2s
- While loop(mid <= high) {
- if(value[mid] == 0), swap it with value[low], low++, mid ++
- else if value[mid] == 2, swap it with value[high], high --
- else if value[mid] == 1, mid++
}
*/
void swap(vector <int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high) {
        if(nums[mid] == 0) {
              swap(nums, low, mid);
               low ++;
               mid ++;
            }
        // Just increment mid
        else if(nums[mid] == 1) {
            mid++;
            }
        else {
            swap(nums, mid, high);
            high --;
            }
        }
    }
};
