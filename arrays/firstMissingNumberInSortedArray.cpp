//M1: Method 1 (Linear Search)
//If arr[0] is not 0, return 0. Otherwise traverse the input array starting from index 0.
//for each pair of elements a[i] and a[i+1], find the difference between them.
//if the difference is greater than 1 then a[i]+1 is the missing number.
//Time Complexity: O(n)


// M2:
//Time Complexity: O(Logn)
#include <iostream>

using namespace std;
int firstMissingElement(int arr[], int start, int end) {
    int mid;
    if(start>end)
        return end+1;
    else if(start != arr[start]) {
        return start;
    }
    mid = (start+end)/2;
    if(mid = arr[mid]){
        return firstMissingElement(arr, mid+1, end);
    return firstMissingElement(arr, start, mid);
    }
}
int main()
{
    int size;
    cin>>size;
    int a[size];
    for (int i=0; i<size; i++) {
        cin>>a[i];
    }
    cout<<firstMissingElement(a, 0, size);

    return 0;
}
