// Problem: https://www.geeksforgeeks.org/a-product-array-puzzle/
#include<iostream>
using namespace std;
int main()
 {
int T, n;
	cin>>T;
	int i, j; 
	for (int k=0; k<T; k++)
	{
	    cin>>n;
	    int arr[n];
	    for(int j=0; j<n; j++)
	    {
	        cin>>arr[j]; 
	    }
	    if (n == 1) { 
        cout << 0; 
        return 0;
    } 
	int* left = new int[sizeof(int) * n]; 
    int* right = new int[sizeof(int) * n]; 
    int* prod = new int[sizeof(int) * n]; 
    left[0] = 1; 
    right[n-1] = 1;
    for(int i=1; i<n; i++) {
        left[i] = arr[i-1]*left[i-1];
    }
    for(int j=n-2; j>=0; j--) {
        right[j] = arr[j+1]*right[j+1];
    }
    for(int i=0; i<n; i++) {
        prod[i] = left[i]*right[i];
        cout<<prod[i]<<" ";
    }
    cout<<endl;
	}
	return 0;
}

//Method 2: Space Complexity-O(1)
#include<iostream>
using namespace std;
int main()
 {
int T, n;
	cin>>T;
	int i, j; 
	for (int k=0; k<T; k++)
	{
	    cin>>n;
	    int arr[n];
	    for(int j=0; j<n; j++)
	    {
	        cin>>arr[j]; 
	    }
	    if (n == 1) { 
        cout << 0; 
        return 0;
    }
    int* prod = new int[sizeof(int) * n]; 
    int temp = 1; 
    for(int i=0; i<n; i++) {
        prod[i] = temp;
        temp = temp*arr[i];
    }
    temp = 1;
    for(int j=n-1; j>=0; j--) {
        prod[j] = prod[j]*temp;
        temp = temp*arr[j];
    }
    for(int i=0; i<n; i++) {
        cout<<prod[i]<<" ";
    }
    cout<<endl;
	}
	return 0;
}
