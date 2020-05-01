//Problem: https://www.interviewbit.com/problems/excel-column-number/
/*
Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 
*/

// Solution Approach:
/*
* ans = 0
* for i = n-1 to 0
*incrememt ans by (A[i]-64) * 26^(n-1-i)
*
*/
//number = 26^0 * (S[n - 1] - ‘A’ + 1) + 26^1 * (S[n - 2] - ‘A’ + 1) + ….
int Solution::titleToNumber(string A) {
    int n = A.length();
    int ans = 0;
    for (int i = n-1; i>=0; i--){
        ans += pow(26, n-1-i) * (A[i] - 'A' + 1);
    }
    
    return ans;
}
