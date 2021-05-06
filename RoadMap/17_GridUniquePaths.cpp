/*
Approach 1: Recursive solution T.C- exponential, S,C - exponential(Stack calls)
- Make a fxn countPaths and pass starting and ending indices of the matrix
- Base conditions - If staring indices exceeds ending indices or we reach till the ending index
- Call the same fxn for right path and downward path
- i,j = current indices and m,n- ending indices
- If(i>m || j>n) return 0;
- if( i== m-1 and j == n-1) return 1;
- return countPaths(i+1,j) + countPaths(i,j+1)
Approach 2: DP T.C - O(n*m), S.C- O(n*m)
- Initialise the matrix with -1
- Store the answer in tp[i][j] for current index
- Before callling the recursive fxn, check if it is already present or not
Apptoach 3: Using combinatorics T.C- O(m-1) or O(n-1), S.C - O(1)
- Total number of directions for moving rightwards = n-1
- Total number of directions for moving downwards = m-1( means number of rows - 1)
- Total directions = n-1 + m-1 = m+n-2
- We just need to choose n-1 unique rightward directions or m-1 unique downward directions
- Answer would be = m+n-2Cm-1 or m+n-2Cn-1
*/
// Approach 3 Implementation - Most optimized
/*class Solution {
public:
    int uniquePaths(int m, int n) {
        int total = m+n-2;
        int r = m-1;
        double ans = 1;
        // calculate totalCr (nCr)
        for (int i=0; i<r; i++) {
            ans *= (double)(total-i));
            ans /= i+1;
        }
        return round(ans);
    }
};*/
int countPaths(int i, int j, int destA, int destB, vector <vector<int>>&tp) {
    // Base condition: If i and j exceeds its limits
    if(i > destA || j > destB){
        return 0;
    } else if(i == destA and j == destB) {
        return 1;
    }
    if(tp[i][j] != -1) 
        return tp[i][j];
    return tp[i][j] = countPaths(i+1, j, destA, destB, tp) + countPaths(i, j+1, destA, destB, tp);
    
}
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector <vector<int>>tp(m, vector<int>(n, -1));
        int ans = countPaths(0, 0, m-1, n-1, tp);
        return ans;
    }
};
