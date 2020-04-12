//https://www.interviewbit.com/problems/maxspprod/
int Solution::maxSpecialProduct(vector<int> &A) {
    // We need to find nearest large element in the left and nearest large element in the right for every element

    int n = A.size();
    vector <int> NearestLargeLeft(n, 0);
    vector <int> NearestLargeRight(n, 0);
    stack <int> stk;
    //To find nearest large element at the right
    for (int i=0; i<n; i++){
        if(stk.empty() or A[stk.top()] >= A[i]){
            stk.push(i);
            continue;
        }
        else{
            while(!stk.empty() and A[stk.top()] < A[i]){
                NearestLargeRight[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
    }
    while(!stk.empty()){
        stk.pop();
    }
    for (int i=n-1; i>=0; i--){
        if(stk.empty() or A[stk.top()] >= A[i]){
            stk.push(i);
            continue;
        }
        else{
            while(!stk.empty() and A[stk.top()] < A[i]){
                NearestLargeLeft[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
    }
    long long int maxProd = INT_MIN;
    for (int i=0; i<n; i++){
        
       // long long int prod = (long long)((long long)NearestLargeRight[i]*(long long)NearestLargeLeft[i])%1000000007;
        
        maxProd = max(maxProd, NearestLargeLeft[i]*1LL*NearestLargeRight[i]);
    }
   
    return maxProd%1000000007;
}
