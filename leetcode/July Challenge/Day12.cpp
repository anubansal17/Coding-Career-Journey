// https://leetcode.com/problems/reverse-bits/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverse;
        bool negative = false;
        if(n>>31 == 1) {
            negative = true;
        }
        // n&1: isolates the last bit from n
        // reverse|(n&1) maps that last bit with result
        // For a signed(negative) integer, reverse is always a 2's complement
        // If the first bit of the input is 1, then its a negative number
        // Add 1 to the number to convert it to 2's complement
        for(int i=0; i<31; i++) {
            reverse = reverse|n&1;
            reverse = reverse<<1;
            n = n>>1;
        }
        
        return negative?reverse+1:reverse;
    }
};
