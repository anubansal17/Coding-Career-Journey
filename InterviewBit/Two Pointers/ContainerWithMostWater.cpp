//https://www.interviewbit.com/problems/container-with-most-water/
//M1 : Brute Force approach - O(n^2)
/*int Solution::maxArea(vector<int> &A) {
    int n = A.size();
    int maxArea = INT_MIN;
    if (n==1){
        return 0;
    }
    for (int i=0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            maxArea = max(maxArea, min(A[i], A[j])* (j-i));
        }
    }
    return maxArea;
}
*/
//M2 - O(n) Approach
int Solution::maxArea(vector<int> &A) {
    int n = A.size();
    int s = 0, e = n-1;
    int maxArea = 0;
    while(s<=e){
        int area = (e-s)*min(A[s], A[e]);
        maxArea = max(area, maxArea);
        if(min(A[s], A[e]) == A[s]){
            s++;
        } else{
            e--;
        }
    }return maxArea;
}
