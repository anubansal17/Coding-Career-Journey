/**Problem Statement:
*
* Hamming distance between two non-negative integers is defined as the number of positions at which the corresponding bits are different.
* For example,
* HammingDistance(2, 7) = 2, as only the first and the third bit differs in the binary representation of 2 (010) and 7 (111).

* Given an array of N non-negative integers, find the sum of hamming distances of all pairs of integers in the array.
* Return the answer modulo 1000000007.

* Example

* Let f(x, y) be the hamming distance defined above.

* A=[2, 4, 6]

* We return,
* f(2, 2) + f(2, 4) + f(2, 6) + 
* f(4, 2) + f(4, 4) + f(4, 6) +
* f(6, 2) + f(6, 4) + f(6, 6) = 

* 0 + 2 + 1
* 2 + 0 + 1
* 1 + 1 + 0 = 8
*
**/
//Method1-O(n^2)
/*int countSetBits(int z){
        int count = 0;
        while (z>0) {
            if(z&1 > 0) {
            count++;
        }
        z = z>>1;
        }
        return count;
        
    }
int calcHamDist(int x, int y){
        return countSetBits(x^y);
    }
    
int Solution::hammingDistance(const vector<int> &A) {
    
    
    int ham_dist = 0;
    for (int i=0; i<A.size(); i++) {
        for(int j=0; j<A.size(); j++){
            ham_dist += calcHamDist(A[i],A[j]);
        }
    }
    return ham_dist;
}*/
//Method2 - O(n)
    //1: 001
    //3: 011
    //5: 101
    //Number of different bits is equal to (number of set bits)*(number of uset bits)  
int Solution::hammingDistance(const vector<int> &A) {

    int ham_dist = 0;
    for (int i=0; i<32; i++){
        int setbits = 0, usetbits = 0;
        for (int j=0; j<A.size(); j++){
            if((A[j] & (1<<i))>0){
                setbits++;
            } else{
                usetbits++;
            }
        }
        ham_dist += 2L*((long)setbits*(long)usetbits)%1000000007;
        ham_dist = ham_dist%1000000007;
    }
    return ham_dist;
}
