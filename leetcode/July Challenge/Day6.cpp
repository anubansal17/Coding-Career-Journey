// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3382/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        // If size of vector is 0
        if(n == 0){
            digits.insert(digits.begin(), 1);
            return digits;
        }
        // Storing last element in some variable
        int cur = digits[n-1];
        int i = 1;
        // While the element at current position is 9, keep on incrementing it
        while(cur == 9 and i < n){
            digits[n-i] = 0;
            i++;
            cur = digits[n-i];
        }
        if(cur < 9){
            digits[n-i]++;
        }
        else{
            digits[n-i] = 0;
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
