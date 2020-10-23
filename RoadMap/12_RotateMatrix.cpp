/*
Approach 1: Brute Force: T.C- O(n^2), S.C - O(n^2)
- Make a new matrix and keep filling its columns from last with rows of first matrix from begining
Approach 2: T.C- O(n^2), S.C- O(1)
- First do transpose of the given matrix
- Then reverse the rows and boom, matrix would be inverted
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(int i=0; i<n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
