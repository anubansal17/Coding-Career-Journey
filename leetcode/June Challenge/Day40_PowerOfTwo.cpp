// https://leetcode.com/explore/featured/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3354/
bool checkIfPossible(int n) {
    int left = 1, right = n/2;
    if(n == 0){
        return 0;
    }
    if(n == 1) {
        return 1;
    }
    int mid;
    while(left <= right) {
        mid = left + (right - left)/2;
        if(pow(2, mid) == n) {
            return 1;
        }
        else if(pow(2, mid) < n) {
            left = mid + 1;
        } else 
        {
            right = mid - 1;
        }
            
    }
    return 0;
}
class Solution {
public:
    bool isPowerOfTwo(int n) {
      bool ans;
        ans = checkIfPossible(n);
        return ans;
    }
};
