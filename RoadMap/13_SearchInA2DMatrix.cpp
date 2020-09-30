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
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
    }
};
