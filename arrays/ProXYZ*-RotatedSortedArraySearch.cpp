//https://www.interviewbit.com/problems/rotated-sorted-array-search/
int Solution::search(const vector<int> &A, int B) {
// 4 5 6 7 0 1 2 3
// 0 1 2 3 4 5 6 7 : indexes after rotating

// 0 1 2 3 4 5 6 7
// 0 1 2 3 4 5 6 7
    int n = A.size();
    int left = 0;
    int right = n-1;
    int smallestNoIndex = -1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(A[mid] > A[n-1]){
            left = mid + 1;
        } else {
            smallestNoIndex = mid;
            right = mid - 1;
        }
    }
    left = 0;
    right = n-1;
    while (left <= right){
        int mid = left + (right-left)/2;
        int newIndex = (mid + smallestNoIndex)%n;
        if(A[newIndex] > B){
            right = mid -1;
        } else if(A[newIndex] < B){
            left = mid + 1;
        } else {
            return newIndex;
        }
    }
    return -1;
}
