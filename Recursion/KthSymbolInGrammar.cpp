// https://leetcode.com/problems/k-th-symbol-in-grammar/submissions/
class Solution {
    // row 1: 0
    // row 2: 01
    // row 3: 0110
    // row 4: 01101001
    // Pattern: Till middle, elements are remaining same and after middle element,         // elements are reverse of the corresponding element in first half(curPosition-mid)
    // Elements oin array are 1 indexed
    // Length of rows are increasing by 2^n-1
public:
    int kthGrammar(int N, int K) {
        // Base condition: if row 1 and column 1 then return 0
        if(N == 1 and K == 1) {
            return 0;
        }
        
        // Condition to check if the element lies in first half or the next half
        int mid = pow(2,N-1)/2;
        if(K <= mid) {
            return kthGrammar(N-1, K);
        } else {
            return !kthGrammar(N-1, K-mid);
        }
    }
};
