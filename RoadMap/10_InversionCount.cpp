//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(vector<long long> &arr, int start, int mid, int end, int &count) {
        int i=start,j = mid;
        int index = 0;
        vector<long long> arr1(end-start);
        while(i < mid && j < end) {
            if(arr[i] <= arr[j]){
                arr1[index] = arr[i];
                index++;
                i++;
            } else{
                count += mid-i;
                arr1[index] = arr[j];
                index++;
                j++;
            }
        }
        
        for(int k=i; k<mid; k++) {
            arr1[index] = arr[k];
            index++;
        }
        for(int k=j; k<end; k++) {
            arr1[index] = arr[k];
            index++;
        }
        int index1 = start;
        for(int k=0; k<arr1.size(); k++) {
            arr[index1] = arr1[k];
            index1++;
        }
        
    }
    void mergeSort(vector<long long> &arr, int start, int end, int &ans) {
        int n = arr.size();
        int mid = (start+end)/2;
        //cout<<start<<" "<<end<<" "<<n<<endl;
        if(start == end-1){
            return;
        }
        
        mergeSort(arr, start, mid, ans);
        mergeSort(arr, mid, end, ans);
        merge(arr, start, mid, end, ans);
        
    }
    long long int inversionCount(vector<long long> &arr) {
        int ans = 0;
        int n = arr.size();
        mergeSort(arr, 0, n, ans);
        // for(int i=0; i<arr.size(); i++) {
        //     cout<<arr[i]<<" ";
        // }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<long long> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        long long num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
    }

    return 0;
}

// } Driver Code Ends
