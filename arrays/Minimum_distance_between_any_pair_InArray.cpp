#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
int main()
 {
int T, n;
	cin>>T;
	for (int i=0; i<T; i++)
	{
	    cin>>n;
	    int arr[n];
	    for(int j=0; j<n; j++)
	    {
	        cin>>arr[j]; 
	    }
	    sort(arr, arr+n);
	    int diff = INT_MAX;
	    for (int i = 0; i < n-1; i++)
	    {
	        if(arr[i+1]-arr[i] <= diff)
	        {
	            diff = arr[i+1] - arr[i];
	        }
	    }
	    cout<<diff<<endl;
	}

	return 0;
}
