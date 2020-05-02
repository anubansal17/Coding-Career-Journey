//https://www.interviewbit.com/problems/implement-power-function/
int calcPower(long int x, int n, int d){
    long long int ans = 1;
     if(n == 1 ){
        return x;
    }
    if (n == 0){
        return 1;
    }
    if(n%2 == 0){
       ans =  calcPower((x*x)%d, n/2, d)%d; 
    }else{
        n = n-1;
        ans =  (x) * calcPower((x*x)%d, n/2, d)%d;
    }
    return ans;
}
int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    // Approach: x ^ n = (x * x) ^( n/2)
    long int ans = calcPower(x, n, d);
    if(ans<0){
        return (d+ans)%d;
    }
    return ans%d;
}
