//https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3319/

class Solution {
public:
    int findComplement(int num) {
        int n = num;
        int ans = 0;
        int i = 0;
       int temp = 0;
        while(num>0){
           temp = ((num)&1)^1;
            cout<<temp;
            ans += pow(2,i)*temp;
            i++ ;
            num >>= 1;
        }
       
        return ans;
    }
};
