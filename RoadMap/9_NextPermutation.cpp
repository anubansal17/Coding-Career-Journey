/* 
Approach 1: Brute force, T.C - O(n!)
Approach 2: Optimized one, T.C - O(n)
- Base condition: Check if it is the highest permutation possible with these numbers
- In dictionary, the right part is always an increasing sequence, so we just need to find the point where this increasing sequence is ending
- For this, Traverse from left and check for first a[i] < a[i+1] - index1
- Now, traverse from left and check the smallest number which is grater than nums[index1] - index2
- Swap nums[index1] with nums[index2]
- Reverse this increasing sequence to have the lowest combination of numbers according to dictionary
*/
void swap(vector<int> &nums, int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        // Check if the size of the array is 1
        if(n == 1) {
            return;
        }
        // check if its the highest permutation possible
        if(nums.size() > 1 && nums[0]>nums[nums.size()-1]){
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i=0; i<n-1; i++) {
            if(nums[i] < nums[i+1]) {
                index = i;
            }
        }
        for (int i = n-1; i >= 0; i--) {
            // Finding the smallest element at the right side which is greater than the breaking point and break the loop there
            if(nums[i] > nums[index]) {
                swap(nums, i, index);
                break;
            }
        }
        if(index != n-1) {
         reverse(nums.begin()+index+1, nums.end());   
        }
    }
};
