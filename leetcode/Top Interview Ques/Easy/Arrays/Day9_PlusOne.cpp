// Problem: https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/559/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
         int carry = 0;
        int n = digits.size();
        for(int i=0; i<n; i++){
            if(digits[i]==9){
                digits[i] = 0;
                if(i == n-1){
                    digits.push_back(1);
                    break;
                }
                carry = 1;
            }else if(carry != 0){
                digits[i] = digits[i]+carry;
                break;
            }else{
                digits[i] = digits[i]+1;
                break;
            }
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
