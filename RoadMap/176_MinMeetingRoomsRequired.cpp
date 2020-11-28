bool comp(vector <int> &A, vector <int> &B){
    return A[0]<B[0];
}

int Solution::solve(vector<vector<int> > &A) {
    int size = A.size();
    if(size == 0) {
        return 0;
    }
    sort(A.begin(),A.end(),comp);
    int ans=1;
    priority_queue <int, vector<int>, greater<int> > pq;
    pq.push(A[0][1]);
    for(int i=1;i<A.size();i++) {
        if(A[i][0]>=pq.top()) {
            pq.pop();
        }
        else{
            ans++;
        }
        pq.push(A[i][1]);
    }
    return ans;
}
