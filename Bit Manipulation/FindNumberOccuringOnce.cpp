//https://www.interviewbit.com/problems/single-number-ii/
// 1 2 4 3 3 2 2 3 1 1
// 4 - ans
// Think about bits of these numbers
// if a number is coming n times then its set bit will also come n times
// 1: 0 0 1
// 2: 0 1 0
// 3: 0 1 1
// 4: 1 0 0
// 0th bit -> 6times (1->3),(3->3)
// 1th bit -> 6times (2->3),(3->3)
// 2nd bit -> 1time (4->1)
int Solution::singleNumber(const vector<int> &A) {
    int ans = 0;
    
    for (int i=0; i<32; i++){
        int setCount = 0;
        for (int j=0; j<A.size(); j++) {
            if((A[j] >> i)&1){
                setCount ++;
            }
        }
        if(setCount%3 != 0 ){
            ans |= (1<<i);
        }
    }
    return ans;
}
