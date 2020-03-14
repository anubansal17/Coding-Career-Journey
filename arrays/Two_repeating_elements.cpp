// Problem: https://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/
#include<iostream>
using namespace std;
int main()
 {
int T, n;
	cin>>T;
	for (int i=0; i<T; i++)
	{
	    cin>>n;
	    int arr[n+2];
	    int count[n+2]={0};
	    for(int j=0; j<n+2; j++)
	    {
	        cin>>arr[j]; 
	    }
	    for(int i=0; i<n+2; i++) {
	        if(count[arr[i]] == 1) {
	            cout<<arr[i]<<" ";
	        }
	        else {
	            count[arr[i]]++;
	           
	        }
	        
	    }
	    cout<<endl;
	    
	}
	return 0;
}
