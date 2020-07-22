#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector <int> wt, vector<int> val, int n, int w) {
    int dp[n+1][w+1];
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=w; j++) {
            // initialisation
            if(i == 0 or j == 0) {
                dp[i][j] = 0;
            }
            
            // if current weight is greater than the reqd one
            else if(wt[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            }
            // taking the maximum of the values found by considering it or by not considering it
            else {
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
            }
        }
        
    }
    return dp[n][w];
}
int main()
 {
int T, n;
	cin>>T;
	for (int i=0; i<T; i++)
	{
	    cin>>n;
	    int w;
	    cin>>w;
	    vector<int> wt; 
	    vector <int> val;
	    for (int j=0; j<n; j++) {
	        int x;
	        cin>>x;
	        val.push_back(x);
	    }
	   
	    for (int j=0; j<n; j++) {
	        int x;
	        cin>>x;
	        wt.push_back(x);
	    }
	    int ans = knapsack(wt, val, n, w);
	    cout<<ans<<endl;
	}
	return 0;
}
