// 1D DP
class Solution{
  public:
    int cutRod(int arr[], int n) {
        int dp[n+1] = {0};
        for (int i=1; i<=n; i++) {
           for(int j=1; j<=i; j++) {
                   dp[i] = max(arr[j-1]+dp[i-j], dp[i]);
        }
    }
        return dp[n];
    }
};
// 2D DP
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int knapsack(vector <int>wt, vector <int> val, int W,int n) 
{ 
    // dp[i] is going to store maximum value 
    // with knapsack capacity i. 
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int j=0; j<=W; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (wt[i-1] < j) {
                dp[i][j] = max(val[i-1] + dp[i][j-wt[j-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
} 
int main()
 {
int T, n;
	cin>>T;
	for (int i=0; i<T; i++)
	{
	    cin>>n;
	    int n;
	    vector <int> price;
	    vector <int> lengthArray;
	    for (int j=0; j<n; j++) {
	        int x;
	        cin>>x;
	        price.push_back(x);
	        lengthArray.push_back(j+1);
	    }
	    int maxPrice;
	    // As max length can be only n
	    // Setting up analogy with  unbounded knapsack
	    maxPrice = knapsack(lengthArray, price, n, n);
	    cout<<maxPrice<<endl;
	}
	return 0;
}
