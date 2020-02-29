#include<iostream>
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
	    int res = arr[0];
	    for(int i=1; i<n; i++)
	    {
	        res = res ^ arr[i];
	    }
	    cout<<res<<endl;
	    
	}
	return 0;
}
