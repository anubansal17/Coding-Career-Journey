// Problem: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3324/
class Solution {
public:
    bool checkPerSqr(int l, int r, int num){
     while(l<=r){
       long long int mid = l + (r-l)/2;
         //long long int ans = mid*mid;
        if(mid*mid == num){
            return true;
        } else if(mid*mid < num){
            l = mid + 1;
        } else{
            r = mid - 1;
        }  
     }
        return false;
        
    }
    bool isPerfectSquare(int num) {
        if(num == 1){
            return true;
        }
      bool ans = checkPerSqr(0, num, num); 
        return ans;
    }
};
