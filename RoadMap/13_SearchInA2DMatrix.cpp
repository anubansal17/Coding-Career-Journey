/*
GFG Problem: https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
- In GFG que, it is not clearly mentioned if the last element in the (n-1)th row is less than first element of nth row
- This clarifying ques makes much difference
- Approach 1: Brute Force T.C- O(n*m)
- Approach 2: Go to each row and do binary search in that row T.C- O(nLogm)
- Approach 3: T.C - O(n+m)
- Go to top most right corner of the matrix and then compare this element
- with the required element to be searched. If the current element turns out to be greater than the required element, move in the left side of row and if it turns out to be lesser then move to the one bottom in the same column
- Approach 4; T.C- O(log(m*n))
- As in leetcode problem, we are given that the first integer of each row is greater than the last integer of the previous row.
- Consider the matrix as imaginary array and for the index mapping, do i/m - row_index and i%m - column_index where m is no of columns
- Apply the binary search for 0 to n*m-1
- For index mapping, use above formula
-- 3rd and 4th approach works incase given matrix is row and column wise sorted
-- 3rd approach will work on both ques
-- 4th approach will work iff the last element in the (n-1)th row is less than first element of nth row
*/
// 3rd Approach Implementation
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int n = matrix.size();
        if(n == 0) {
            return false;
        }
        int m = matrix[0].size();
        int i = 0, j = m-1;
        while(i < n && j >= 0) {
            if(matrix[i][j] == target) {
                return true;
            } else if(matrix[i][j] < target) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};

// 4th Approach Implementation
class Solution {
public:
    bool binarySearch(int start, int end, int target, vector<vector<int>> &matrix, int cols) {
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(matrix[mid/cols][mid%cols] == target)
                return 1;
            else if(matrix[mid/cols][mid%cols] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return 0;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n-1;
        return binarySearch(0, n*m-1, target, matrix, n);
    }
};
