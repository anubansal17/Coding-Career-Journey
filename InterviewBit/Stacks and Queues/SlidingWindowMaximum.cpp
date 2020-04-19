//https://www.interviewbit.com/problems/sliding-window-maximum/
//M1- Brute force:O(n^2)
//M2- Segment Tree:O(nlogn)
//M3- Using double ended queue: O(n)
// 4 7 8 3 2 5
//Algo:
// Add first element into dq
// For the next element check if the element is greater or lesser than the element at the back of queue
// If the element is lesser than the back element in the queue then add its index to the queue,
// as it might be answer for other upcoming elements in the array
// If the element is greater than the element at index stored at back of the queue, we will simply remove the back element and add this element's index
// Along with this we will keep removing unused elements in the queue, which are not in current window
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    int n = A.size();
    deque <int> dq;
    vector <int> ans;
    for (int i=0; i<n;i++){
        if(i>=B){
            ans.push_back(A[dq.front()]);
            if(!dq.empty() and dq.front() <= i-B){
                dq.pop_front();
            }
        }
        if(dq.empty() or A[dq.back()]>A[i]){
            dq.push_back(i);
            continue;
        }
        else{
            while(!dq.empty() and A[dq.back()]<= A[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
    }
    ans.push_back(A[dq.front()]);
    return ans;
}
