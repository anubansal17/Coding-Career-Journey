// Problem: https://www.interviewbit.com/problems/number-of-1-bits/
/*
The 32-bit integer 11 has binary representation

00000000000000000000000000001011
so the function should return 3
*/
int Solution::numSetBits(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int count = 0;
    while(A>0){
        if((A)&1){
            count ++;
        }
        A >>= 1;
    }
    return count;
}
