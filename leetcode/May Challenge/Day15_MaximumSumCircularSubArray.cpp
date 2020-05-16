//https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3330/
int kadane(vector <int> A, int n){
   int max = 0;
    int tempMax = 0;
        for (int i=0; i<n; i++){
            tempMax += A[i];
            if(tempMax < 0){
                tempMax = 0;
            }
            else if(tempMax>max){
                max = tempMax;
            }
        }
    return max;
}

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
      int n = A.size();
        int max = INT_MIN;
        bool flag = false;
        // To check if all elements are negative
        for (int i=0; i<n; i++){
            if(A[i]<0){
                if(A[i]>max){
                    flag = true;
                    max = A[i];
                }
            }else{
                    flag = false;
                    break;
                }
        }
        if (flag){
            return max;
        }else{
            max = 0;
        }
        int maxA = 0;
        int maxB = 0;
        int totalSum = 0;
        // To consider the case where wrapping is not present - Kadane's Algo
        maxA  = kadane(A, n);
        // To consider the case where wrapping is present
        for (int i=0; i<n; i++){
            totalSum += A[i];
            A[i] = -A[i];
        }
        maxB = totalSum + kadane(A, n);
        return maxA>maxB?maxA:maxB;
    }
};
