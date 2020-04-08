//https://www.interviewbit.com/problems/min-xor-value/
int Solution::findMinXor(vector<int> &A) {
// [0 2 5 7]
// Approach: sort the array and then minimum xor value would be minimum of xor values of two consecutive numbers
int ans = INT_MAX;
sort(A.begin(), A.end());
for (int i=0; i<A.size()-1; i++){
        ans = min(ans, A[i]^A[i+1]);
    
}
    return ans;
}
