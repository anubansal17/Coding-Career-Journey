#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

bool hasPairWithReqdSum(int arr[], int n, int sum)
{
    unordered_map <int, int> hash;
    for (int i=0; i<n; i++)
    {
        if(hash[sum - arr[i]] == 0)
            hash[arr[i]]= 1;
        else
            return true;
    }

    return false;
    
}

int main()
 {
int T, n, sum;
bool res;
	cin>>T;
	for (int i=0; i<T; i++)
	{
	    cin>>n;
	    cin>>sum;
	    int arr[n];
	    for(int j=0; j<n; j++)
	    {
	        cin>>arr[j]; 
	    }
	    res = hasPairWithReqdSum(arr, n, sum);
	    if(res == true)
	        cout<<"Yes"<<endl;
	   else
	        cout<<"No"<<endl;
	    
	}
	return 0;
}
