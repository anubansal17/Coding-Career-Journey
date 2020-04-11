//https://www.interviewbit.com/problems/nearest-smaller-element/
//A = [4, 5, 2, 10, 8]
//8 10 2
//2 5
//2 4
vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector <int> v(n, -1);
    stack <int> stk;
    for (int i=n-1; i>=0; i--){
        if(!stk.empty() and A[stk.top()]<=A[i]){
            stk.push(i);
            continue;
        }
        while(!stk.empty() and A[stk.top()]>A[i]){
            v[stk.top()] = A[i];
            stk.pop();
        }
        stk.push(i);
    }
    return v;
}
