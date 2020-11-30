// We need to find nearest smallest smaller element at the left side
vector<int> Solution::prevSmaller(vector<int> &A) {
    vector <int> ans;
    stack <int> stk;
    int n = A.size();
    // Check if stack is empty then push -1 in the answer vector
    for (int i=0; i<n; i++) {
        if(stk.empty()) {
            ans.push_back(-1);
        }
        else {
            // If stack is not empty
            if(stk.top() < A[i]) {
                ans.push_back(stk.top());
            } else {
                // Keep popping from the stack till we get any element smaller than the current element
                while(!stk.empty() and stk.top() >= A[i]) {
                    stk.pop();
                }
                // If stack becomes empty, no smaller element exists at the left side
                if(stk.empty()) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(stk.top());   
                }
            }
        }
        stk.push(A[i]);
    }
    return ans;
}
