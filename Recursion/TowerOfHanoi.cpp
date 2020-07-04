// https://practice.geeksforgeeks.org/problems/tower-of-hanoi/0
#include<iostream>
using namespace std;
void solve(int s, int d, int h, int n, int &count) {
    if(n == 1) {
        cout<<"move disk "<<n<<" from rod "<<s<<" to rod "<<d<<endl;
        count ++;
        return ;
    }
    // Moving n-1 remaining disks from source to helper with help of disk3
    solve(s,h,d,n-1,count);
    cout<<"move disk "<<n<<" from rod "<<s<<" to rod "<<d<<endl;
    count ++;
    // Moving n-1 remaining disks from helper(Disk2) to disk3 with the help of source(Disk1)
    solve(h,d,s,n-1,count);
    
}
int main()
 {
int T, n;
	cin>>T;
	// Disk1 - Source
	// Disk2 - Helper disk
	// Disk3 - Destination disk
	for (int i=0; i<T; i++)
	{
	    cin>>n;
	    int count=0;
	    solve(1, 3, 2, n,count);
	    cout<<count<<endl;
	}
	return 0;
}

