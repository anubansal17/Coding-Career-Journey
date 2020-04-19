//https://www.interviewbit.com/problems/largest-rectangle-in-histogram/
int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size();
    vector <int> NearestSmallLeft(n, -1);
    vector <int> NearestSmallRight(n, n);
    stack <int> stk;
    //Finding the nearest small element at the right side for every element of the vector
    for (int i=0; i<n; i++){
        if(stk.empty() or A[stk.top()] <= A[i]){
            stk.push(i);
            continue;
        }
        while(!stk.empty() and A[stk.top()] > A[i]){
            NearestSmallRight[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while(!stk.empty()){
        stk.pop();
    }
    for (int i=n-1; i>=0; i--){
        if(stk.empty() or A[stk.top()] <= A[i]){
            stk.push(i);
            continue;
        }
        while(!stk.empty() and A[stk.top()] > A[i]){
            NearestSmallLeft[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    
    int ans = 0;
    for (int i=0; i<n; i++){
        int tempAns = A[i] * (NearestSmallRight[i] - NearestSmallLeft[i] + 1 - 2);
        ans = max(ans, tempAns);
        // -2 to exclude nearestSmallRight and NearestSmallLeft element
    }
    return ans;
   
}
