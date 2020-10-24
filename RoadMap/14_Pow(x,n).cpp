// edge case can be there when n = INT_MIN
double pow(double x, int n) {
        // Base condition
        if(n == 0) {
            return 1;
        }
        else if(n == 1) {
            return x;
        }

        double ans = 1;
        if(n%2 == 0) {
            ans = pow(x*x, n/2);
        } else {
            ans = pow(x*x, n/2);
            ans = ans * x;
        }
    return ans;
}
class Solution {
public:
    double myPow(double x, int n) {
    double ans = pow(x, n);
        if(n < 0) {
            return 1/ans;
        }
        return ans;
    }
};
