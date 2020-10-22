/*
Approach 1: Brute Force, T.C- O(n*m)(n+m), S.C- O(1)
- Provided if the elements in the given matrix will be all positive integers
- Iterate over the matrix if any zero is found, make it's row and column as -1 inplace of 1s, not 0s
- At last, make all -1s as 0's

Approach 2: Using 2 dummy arrays, T.C - O(n*m), S.C- O(max(n+m))
- Take 2 dummy arrays, one of size as number of rows and other of size as number of columns
- Traverse the matrix, and if any zero is found make the element at corresponding row and column in dummy arrays as 0
- After traversing the complete matrix this way, you would be having zeroes at some of the places at these dummy arrays
- Now, traverse the matrix again and check for values at these dummy arrays
- If any of the value in dummy arrays is 0, make the element in the matrix for corresponding index as 0

Approach 3: Instead of taking 2 explicit dummy arrays, use first row and first column of matrix as dummy arrays, T.C- O(n*m), S.C- O(1)
- Rest of the algo would be same as above
- As matrix[0][0] can be set by two different rows and column, we will handle this case separately
*/
// Approach 3 implementation
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // using 1st row and 1st column as dummy arrays
        int n = matrix.size();
        int m = matrix[0].size();
        bool firstColumn = 0;
        // Checking for first column
        for (int i=0; i<n; i++) {
            if(matrix[i][0] == 0) {
                firstColumn = 1;
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=1; j<m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // Starting from (1,1) to avoid tampering our prepared dummy row and column
        for (int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // check if first row to be set as 0
        if(matrix[0][0] == 0) {
          for (int j=0; j<m; j++) {
                matrix[0][j] = 0;
            } 
        }
        // tampering the first col
        if(firstColumn == 1) {
            for (int i=0; i<n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
