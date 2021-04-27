class Solution{
public:
int dp[101][101];
int solve(int arr[], int i, int j) {
        int minAns = INT_MAX;
    // Base condition: Incase i == j, there's only one dimension of matrix which is an invalid input
    if(i >= j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    // two buckets: i to k, k+1 to j
    for(int k=i; k<=j-1; k++) {
        int temp =  solve(arr, i, k) +  solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        minAns = min(minAns, temp);
    }
    return dp[i][j] = minAns;
}
    int matrixMultiplication(int N, int arr[])
    {
        int i=1, j = N-1;
        memset(dp, -1, sizeof(dp));
        int ans = solve(arr, i, j);
        return ans;
    }
};
