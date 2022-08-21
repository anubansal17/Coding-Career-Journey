int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int cur = A[0];
    unordered_map<int, int> mp;
    mp[cur]++;
    int ans = 0;
    if(cur == B)
        ans++;
    for(int i=1; i<n; i++) {
        cur ^= A[i];
        if(cur == B)
            ans++;
        if(mp[cur^B])
            ans += mp[cur^B];
        mp[cur]++;
    }
    return ans;
}
