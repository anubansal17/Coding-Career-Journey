/**
*
* Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0.
* A and P both should be integers.

* Example

* Input : 4
* Output : True  
* as 2^2 = 4. 
*
**/
//M1 - Brute force 
/*int Solution::isPower(int A) {
    if(A==1){
        return 1;
    }
    for(int i=2; i<=sqrt(A); i++){
        for(int j=2; pow(i,j)<=A;j++){
            if(pow(i,j) == A){
                return 1;
            }
        }
    }
    return 0;
}
*/

//M2- Logarithmic approach 
int Solution::isPower(int A) {
    if(A==1){
        return 1;
    }
    float p;
    for (int i=2 ; i<=sqrt(A); i++){
        p = log2(A)/log2(i);
        if(floor(p)==ceil(p)){
            return 1;
        }
    }
    return 0;
    
}
