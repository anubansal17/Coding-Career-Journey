/*
Approach 1: Use an extra array and merge both the arrays in that array after comparing each element, T.C- O(nLogn), S.C- O(n)

Approach 2: Insertion sort: Use the fact that both the arrays are already sorted
- Compare the elements of both the arrays starting from begining - arr1(n1) and arr2(n2)(n1>n2)
- If the element in arr1 is greater than the element in arr2, then swap both the elements
- Sort the second array immediately after this operation which can be done in linear time
- After doing this till last, we can easily append both the arrays as they can be considered as one sorted array
- T.C - O(n1*n2) and S.C- O(1)

Approach 3: Using Gap Algo, T.C- O(n(logn)) and S>C - O(1)
- Gap = ceil(n1+n2)/2;
- with a gap, keep comparing the elements starting from array 1
- As soon as we reach out of second array, make the gap as gap/2 and then start from the first step
- If the gap becomes 1, this would be the last iteration
*/
void swap(vector<int>& nums1, vector<int>& nums2, int i, int j) {
    int temp = nums1[i];
    nums1[i] = nums2[j];
    nums2[j] = temp;
}
void sort(vector<int> &nums) {
    int i = 1;
    while(i<nums.size() and nums[0] > nums[i]) {
        i++;
    }
    nums.insert(nums.begin()+i, nums[0]);
    nums.erase(nums.begin());
}
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for (int i=0; i<m; i++) {
            if(n > 0 and nums1[i] > nums2[0]){
                swap(nums1, nums2, i, 0);
                 sort(nums2);   
            }
        }
        for(int i=0; i<n; i++) {
            nums1[m+i] = nums2[i];
        }
    }
};
