/* 
Approach 1: Brute force, T.C - O(n!)
Approach 2: Optimized one, T.C - O(n)
- Base condition: Check if it is the highest permutation possible with these numbers
- In dictionary, the right part is always an increasing sequence, so we just need to find the point where this increasing sequence is stopping
- For this, Traverse from right and check for first a[i] < a[i+1] - index1
- Now, traverse from left and check the smallest number which is grater than nums[index1] - index2
- Swap nums[index1] with nums[index2]
- Reverse this increasing sequence to have the lowest combination of numbers according to dictionary
*/
void swap(vector <int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index1 = -1;
        int n = nums.size();
        // first element which is lesser than previous element starting from right
        for (int i = n-2; i>=0; i--) {
            if(nums[i]<nums[i+1]) {
                index1 = i;
                break;
            }
        }
        if(index1 == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        //cout<<index1;
        int index2 = index1;
        // first element from right which is greater than element present at index1
        for (int i=n-1; i>index1; i--) {
            if(nums[i] > nums[index1]) {
                index2 = i;
                break;
            }
        }
        //cout<<index2;
       // swap both the elements
        swap(nums, index1, index2);
        reverse(nums.begin()+index1+1, nums.end());
    }
};
