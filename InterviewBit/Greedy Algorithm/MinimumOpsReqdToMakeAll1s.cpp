//https://www.interviewbit.com/problems/bulbs/
int Solution::bulbs(vector<int> &A) {
    int count = 0;
    int n = A.size();
    int res = 0;
    for (int i=0; i<n; i++){
        if(A[i] == 1 and count%2 == 0){
            continue;
        } else if(A[i]==0 and count%2 != 0){
            continue;
        } else if(A[i]==0 and count%2 == 0){
            res ++;
            count ++;
        } else if(A[i]==1 and count%2 != 0){
            res ++;
            count ++;
        }
    }
    return res;
}
