//https://www.interviewbit.com/problems/magician-and-chocolates/
#define mod 1000000007
int Solution::nchoc(int A, vector<int> &B) {
    //priority queue in c++ is by default max_heap
    priority_queue<int> heap;
    int n = B.size();
    for(int i=0; i<n; i++){
        heap.push(B[i]);
    }
    int ans = 0;
    for (int i=0; i<A; i++){
        int val = heap.top();
        ans = (0ll + ans + val) % mod;
        heap.pop();
        heap.push(val/2);
    }
    return ans;
}
