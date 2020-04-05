//https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/
//https://www.interviewbit.com/problems/find-duplicate-in-array/
int Solution::repeatedNumber(const vector<int> &A) {
    int size = A.size();
    bool arr[size] = {false};
    for (int i=0; i<size; i++){
        if(arr[A[i]] == false){
            arr[A[i]] = true;
        }
        else if (arr[A[i]] == true){
            return A[i];
            break;
        }
    }
    return -1;
    
}
