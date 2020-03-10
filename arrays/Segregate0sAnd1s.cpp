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
	    int left=0, right=n-1;
	    while(left<right) {
	        if(arr[left] == 1) {
	            swap(arr[left], arr[right]);
	            right--;
	        }
	        else {
	            left++;
	        }
	    }
	    for(int i=0; i<n; i++) {
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	    
	}
	return 0;
}
