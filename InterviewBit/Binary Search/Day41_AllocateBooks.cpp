// https://www.interviewbit.com/problems/allocate-books/
bool isValidPages(vector<int> &V, int reqdParts, int curMin) {
        int parts = 0;
        int tempSum = 0;
        int n = V.size();
        for (int i=0; i<n; i++){
            // corner case: To cover the case if number of pages at any index is greater than the mid element
            if(V[i]>curMin){
                return 0;
            } 
            tempSum += V[i];
            if(tempSum > curMin){
                tempSum = V[i];
                parts ++;
            }
            if(parts > reqdParts){
                return 0;
            }
        }
        return 1;
}
int findMinimumPages(vector <int> &A, int left, int right, int B) {
    int mid;
    int ans = INT_MAX;
    //cout<<left<<endl;
    //cout<<right<<endl;
    while (left <= right) {
        mid = (left +right)/2;
        if(isValidPages(A, B-1, mid)) {
            //cout<<ans;
          ans = mid;
          right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}
int Solution::books(vector<int> &A, int B) {
    int ans;
    int n = A.size();
    int minm = *min_element(A.begin(), A.end());
    int sum = 0;
    // Corner case: If number of students is greater than total size
    if(n<B){
        return -1;
    }
    for (int i=0; i<n; i++) {
        sum += A[i];
    }
    
    //cout<<minm;
    ans = findMinimumPages(A, 0, sum, B);
    return ans;
}
