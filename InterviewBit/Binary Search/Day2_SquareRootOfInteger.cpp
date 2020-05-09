// Problem: https://www.interviewbit.com/problems/square-root-of-integer/
// Tip: mid*mid gives overflow error, so to avoid that I declared mid as long
int Solution::sqrt(int A) {
    int l = 1;
    int r = A;
    int ans = 0;
    while(l<=r){
        long long int mid = l + (r-l)/2;
        if(mid*mid == A){
            ans = mid;
           
            return ans;
        } else if(mid*mid > A){
            
            r = mid - 1;
        } else{
            ans = mid;
            l = mid + 1;
        }
    }
    return ans;
}

