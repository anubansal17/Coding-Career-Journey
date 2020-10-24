/*
Approach 1: Sort the array
- Three loops + Binary Search T.C - O(n^3Logn(n)), S.C- O(1)

Approach 2: Two loops + two pointers, T.C - O(n^3), S.C- O(1)
- Sort the vector given
- for i= 0 to n-1
-   for j = i+1 to n-1
-       left = j+1
-       right = n-1
-       target2 = target - nums[i] - nums[j]
-       while(left < right){
-       if(nums[left]+nums[right] < target2) left++;
-       else if(nums[left] + nums[right] > target2) right--;
-       else {
-       add these elements as quadruplet to answer
-       increment the left to next distinct element
-       increment the right to next distinct element
-   }
-       }
*/
class Solution {
public:
    vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    int n = A.size();
    vector<vector<int>> ans;
    sort(A.begin(), A.end());
    for (int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int target = B - A[i] - A[j];
            int left = j+1;
            int right = n-1;
            while(left<right) {
                if(A[left]+A[right] < target) {
                    left++;
                }
                else if(A[left]+A[right] > target) {
                    right --;
                }
                else {
                   ans.push_back({A[i], A[j], A[left], A[right]});
                   int leftEle = A[left];
                   int rightEle = A[right];
                    while(left<right && A[left] == leftEle) {
                        left++;
                    }
                    while(left<right && A[right] == rightEle) {
                        right--;
                    }
                }
            }
            // Jumping thru the duplicates
            while(j+1<n && A[j] == A[j+1]) {
                j++;
            }
        }
        // Jumping thru the duplicates
        while(i+1<n && A[i] == A[i+1]) {
                i++;
            }
    }
    return ans;
}
};
