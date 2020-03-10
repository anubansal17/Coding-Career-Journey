#include<iostream>
using namespace std;
int main()
 {
int T;
long int n;
	cin>>T;
	for (int i=0; i<T; i++)
	{
	    cin>>n;
	    long int arr[n];
	    long int a[n];
	    long int index=-1;
	    int max_so_far = 0;
	    for(long int j=0; j<n; j++)
	    {
	        cin>>arr[j]; 
	    }
	    for(long int k=n-1; k>=0; k--) {
	        if(arr[k] >= max_so_far) {
	            index++;
	            a[index] = arr[k];
	            
	            max_so_far = arr[k];
	        }
	    }
	    while(index>=0)
	    {
	        cout<<a[index]<<" ";
	        index--;
	    }
	    cout<<endl;
	    
	}
	return 0;
}
