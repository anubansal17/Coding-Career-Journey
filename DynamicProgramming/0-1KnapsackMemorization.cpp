#include<iostream>
#include<vector>
#include <bits/stdc++.h> 
using namespace std;
int static tp[1002][1002];

// Memorization solution to 0/1 knapsack
int knapsack(vector<int> wt, vector<int> val, int w, int n){
    // Base Condition - If total capacity is 0 or number of items is 0
    if(n == 0 or w == 0){
        return 0;
    }
    if(tp[n][w] != -1) {
        return tp[n][w];
    }
    // If weight of cur item is greater than capacity, we won't choose this item
    if(wt[n-1] > w){
        tp[n][w] = knapsack(wt, val, w, n-1);
        return  tp[n][w];
    } else {
        // Max of two cases
        // First case: if we include the item then profit value
        // Second case: if we don't include the item then profit value
       return tp[n][w] = max(val[n-1]+knapsack(wt, val, w-wt[n-1], n-1), knapsack(wt, val, w, n-1)); 
    }
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
	    // Initialising matrix with -1
        memset(tp, -1, sizeof(tp));
	    ans = knapsack(wt, val, w, n);
	    cout<<ans<<endl;
	}
	return 0;
}
