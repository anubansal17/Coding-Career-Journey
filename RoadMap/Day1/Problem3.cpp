vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    vector <bool> ele(n,false);
    vector <int> ans;
    int dupl;
    for (int i=0; i<n; i++) {
        if(ele[A[i]] != true) {
            ele[A[i]] = true;
        } else{
            dupl = A[i];
            break;
        }
    }
    ans.push_back(dupl);
    long long int sum = 0;
    for(int i=0; i<n; i++) {
        sum += (long long )A[i];
    }
    long long int reqdSum = (long long)n*(long long)(n+1)/2;
    int misdNum = (long long)reqdSum - ((long long) sum - dupl);
    ans.push_back(misdNum);
    return ans;
}
