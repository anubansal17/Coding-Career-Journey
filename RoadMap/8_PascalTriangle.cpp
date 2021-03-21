/* 
Type 1: For this problem, T.C - O(n^2)
Type 2: There can be some other type of problem too where you would need to tell the element at some particular position  in pascal triangle
- In that case, you won't need to find the complete pascal triangle and then tell
- You just need to find the element at that particular position which is (r-1)C(c-1)
- T.C - O(n)
Type 3: Where you would be required to print the complete row of pascal triangle
- To calculate nCr, you can use:
- res *= (n-i)
- res /= i+1
- Pseudo code: initialise res = 1;
- for(int i=0; i<r; i++) {
    res *= n-i
    res /= i+1
    }
Eg- 4C1 = 4/1, 4C2 = 4*(3/2)
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector<int>> pascalTri (numRows);
        for(int i=0; i<numRows; i++) {
            pascalTri[i].resize(i+1);
            pascalTri[i][0] = pascalTri[i][i] = 1;
            for (int j=1; j<i; j++) {
                pascalTri[i][j] = pascalTri[i-1][j-1]+pascalTri[i-1][j];
            }
        }
        return pascalTri;
    }
};
