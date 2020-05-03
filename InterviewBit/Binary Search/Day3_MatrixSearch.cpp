// Problem: https://www.interviewbit.com/problems/matrix-search/
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int row = A.size()-1/2;
    for (int row=0; row<A.size(); row++){
    int l = 0, r = A[row].size() - 1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(A[row][mid] == B){
            return 1;
        }else if(A[row][mid] > B){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    }
    return 0;
    
}
