#include<iostream>
#include<vector>
#include <bits/stdc++.h> 
using namespace std;
int static tp[1001][1001];

// Memorization solution to 0/1 knapsack
int knapsack(vector<int> wt, vector<int> val, int w, int n){
    // Iterative approach - top down
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<w+1; j++) {
            // Base Condition - If total capacity is 0 or number of items is 0
            if(i == 0 or j == 0){
                tp[i][j] = 0;
            }
             // If weight of cur item is greater than capacity, we won't choose this item
            else if(wt[i-1] > j){
                tp[i][j] = tp[i-1][j];
                 
            } else {
                // Max of two cases
                // First case: if we include the item then profit value
                // Second case: if we don't include the item then profit value
                tp[i][j] = max(val[i-1] + tp[i-1][j-wt[i-1]], tp[i-1][j]); 
            }
        }
    }
    return tp[n][w];
}
int main()
 {
int T, n;
	cin>>T;
	for (int i=0; i<T; i++)
	{
	    int n, w;
	    cin>>n;
	    cin>>w;
	    vector<int> wt;
	    vector<int> val;
	     for(int j=0; j<n; j++) {
	        int x;
	        cin>>x;
	        val.push_back(x);
	    }
	    for(int j=0; j<n; j++) {
	        int x;
	        cin>>x;
	        wt.push_back(x);
	    }
	   
	    // w: Weight capacity of knapsack
	    // n: Total number of items
	    int ans = 0;
	    ans = knapsack(wt, val, w, n);
	    cout<<ans<<endl;
	}
	return 0;
}
