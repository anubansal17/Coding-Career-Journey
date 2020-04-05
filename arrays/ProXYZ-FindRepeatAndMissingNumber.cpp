//https://www.interviewbit.com/problems/repeat-and-missing-number-array/
// Another approach of doing it- reqd sum = actual sum + A - B
// reqd sum^2 - actual sum^2 = A^2 - B^2
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int size = A.size();
    vector <bool> arr(size, true);
    int dup = 0;
    for (int i=0; i<size; i++){
        if(arr[A[i]] == true){
            arr[A[i]] = false;
        } else {
            dup = A[i];
            break;
        }
    }
    vector <int> ans;
    ans.push_back(dup);
    long long sum = 0;
    for (int i=0; i<size; i++){
        sum += (long long)(A[i]);
    }
    long long reqdSum = (long long)(size)*(long long)(size+1)/2;
    int missingNum = (long long)reqdSum - (long long)sum + dup;
    ans.push_back(missingNum);
    return ans;
}
