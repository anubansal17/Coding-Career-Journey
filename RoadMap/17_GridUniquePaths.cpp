/*
Approach 1: Recursive solution T.C- exponential, S,C - exponential(Stack calls)
- Make a fxn countPaths and pass starting and ending indices of the matrix
- Base conditions - If staring indices exceeds ending indices or we reach till the ending index
- Call the same fxn for right path and downward path
- i,j = current indices and m,n- ending indices
- If(i>=m || j>=n) return 0;
- if( i== m-1 and j = n-1) return 1;
- return countPaths(i+1,j)+countPaths(i,j+1)
Approach 2: DP T.C - O(n^2), S.C- O(n^2)
- Initialise the matrix with -1
- Store the answer in tp[i][j] for current index
- Before callling the recursive fxn, check if it is already present or not
*/
// Approach 2: Implementation
int countPaths(int i, int j, int m, int n, vector<vector<int>> &tp) {
    // Base condition : If current index exceeds the matrix
    if(i >= m || j >= n) {
        return 0;
    } 
    // If we reach till end of the matrix, i.e. our destination
    else if(i == m-1 && j == n-1) {
        return 1;
    }
    
    else if(tp[i][j] != -1) {
        return tp[i][j];
    }
    return tp[i][j] = countPaths(i+1, j, m, n, tp) + countPaths(i, j+1, m, n, tp);
    
}
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> tp(m, vector<int> (n, -1));
        
        int ans;
        ans = countPaths(0, 0, m, n, tp);
        return ans;
    }
};
