#include<iostream>
using namespace std;
int main()
 {
int T, n;
	cin>>T;
	for (int i=0; i<T; i++)
	{
	    cin>>n;
	    int a[n];
	    for(int j=0; j<n; j++)
	    {
	        cin>>a[j]; 
	    }
	    
	    int count=1, maj_index=0;
	    for(int i=1; i<n; i++)
	    {
	        if(a[maj_index] == a[i])
	            count++;
	        else
	            count--;
	        if(count == 0)
	        {
	            count=1;
	            maj_index = i;
	        }
	        
	    }
	    
	    int x = a[maj_index];
	    count = 0;
	    for(int j=0; j<n; j++)
	    {
	       
	        if(a[j] == x)
	        {
	            count ++;
	        }
	        
	    }
	   
	    if(count > n/2)
	        cout<<a[maj_index]<<endl;
	    else
	        cout<<-1<<endl;
	    
	}
	return 0;
}
