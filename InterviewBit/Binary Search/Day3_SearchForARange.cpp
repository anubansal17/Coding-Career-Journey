// Problem: https://www.interviewbit.com/problems/search-for-a-range/
// Code is absolutely correct but didn't get submitted beacause of some bug in IB's test case
int searchIndex(vector <int>A, int B, bool is_first_occurence){
    int l = 0;
    int r = A.size();
    int ans = -1;
    int mid = -1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(A[mid] == B){
            ans = mid;
            if(is_first_occurence){
                r = mid-1;
            } else{
                l = mid + 1;
            }
        } else if(A[mid] > B){
            r = mid - 1;
        } else{
            l = mid + 1;
        }
    }
    return ans;
}
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    vector <int> ans;
    ans.clear();
    ans.push_back(searchIndex(A, B, true));
    ans.push_back(searchIndex(A, B, false));
    return ans;
}
