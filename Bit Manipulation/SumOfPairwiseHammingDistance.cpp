//https://www.interviewbit.com/problems/different-bits-sum-pairwise/
//Different bits sum pairwise
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
