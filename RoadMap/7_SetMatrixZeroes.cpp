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
        int rows = matrix.size();
        int cols = matrix[0].size();
        int col = 1;
        for (int i = 0; i < rows; i++) {
                // If any of the element in zeroth column is 0
                if(matrix[i][0] == 0) {
                    col = 0;
                }
                for (int j=1; j<cols; j++) {
                // If value is zero at any index
                    if(matrix[i][j] == 0) {
                    // Make corresponding value in first row and first column as 0
                        matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        // In the final iteration, we will start from last to reserve our dummy array
        //cout<<matrix[0][0]<<matrix[1][0];
        // So, we will be updating this dummy array in last
        for (int i = rows-1; i >= 0; i--) {
            for (int j=cols-1; j>=1; j--) {
                if(i == 1 && j == 2){
                   // cout<<matrix[i][0]<<matrix[0][j];
                }
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    cout<<i<<j<<endl;
                    matrix[i][j] == 0;
                }
            }
            // Handling the first column separately
            if(col == 0) {
                matrix[i][0] = 0;
            }
        }
    }
};
