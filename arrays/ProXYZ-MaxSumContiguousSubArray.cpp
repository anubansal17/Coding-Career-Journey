//https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
int Solution::maxSubArray(const vector<int> &A) {
    int sum = 0, maxSum = INT_MIN;
    for (int i=0; i<A.size(); i++) {
       sum = max(0, sum);
       sum += A[i];
       
       maxSum = max(sum, maxSum);
    }
    return maxSum;
}
