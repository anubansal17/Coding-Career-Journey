// Problem: https://www.interviewbit.com/problems/rearrange-array/

// Solution Approach:
// To achieve this increment every element at ith index is incremented by (arr[arr[i]] % n)*n.
// Old value can be obtained by arr[i]%n and a new value can be obtained by arr[i]/n.
// Let’s assume an element is a and another element is b, both the elements are less than n.
// So if an element a is incremented by b*n.
// So the element becomes a + b*n so when a + b*n is divided by n then the value is b and a + b*n % n is a.

void Solution::arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    /*
    *Increase every Array element Arr[i] by (Arr[Arr[i]] % n)*n.
    Divide every element by N.
    */
    int n = A.size();
    for (int i=0; i<n; i++){
        A[i] += (A[A[i]]%n)*n;
      
    }
     for (int i=0; i<n; i++){
         A[i] /= n;
     }
    
}
