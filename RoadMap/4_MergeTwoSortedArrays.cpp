/*
Approach 1: Use an extra array and merge both the arrays in that array after comparing each element, T.C- O(n+m), S.C- O(n)

Approach 2: Insertion sort: Use the fact that both the arrays are already sorted
- Compare the elements of both the arrays starting from begining - arr1(n1) and arr2(n2)(n1>n2)
- If the element in arr1 is greater than the element in arr2, then swap both the elements
- Sort the second array immediately after this operation which can be done in linear time
- After doing this till last, we can easily append both the arrays as they can be considered as one sorted array
- T.C - O(n1*n2) and S.C- O(1)

Approach 3: T.C - O(n1+n2) and S.C - O(1)
- Start comparing from the end of both the arrays,m whichever is greater put that in the end of first array
- Cover the edge cases correctly
*/
// Approach 2: Implementation
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

// Approach 3 Code
class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        int index = arr1.size()-1;
        int i = m-1;
        int j = n-1;
        while(i>=0 && j >= 0){
            if(arr1[i] >= arr2[j]){
                arr1[index] = arr1[i--];
            }
            else{
                arr1[index] = arr2[j--];
            }
            index--;
        }
        
        while(i>=0){
            arr1[index--] = arr1[i--];
        }
        while(j>=0){
            arr1[index--] = arr2[j--];
        }
    }
};
