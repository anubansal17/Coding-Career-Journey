//https://www.interviewbit.com/problems/highest-product/
//M1 - Sorting: O(nlogn)
/*int Solution::maxp3(vector<int> &A) {

    sort(A.begin(), A.end());
    int n = A.size();
    int max1 = A[n-1];
    int max2 = A[n-2];
    int max3 = A[n-3];
    int min1 = A[0];
    int min2 = A[1];
    if(max1*max2*max3 > max1*min1*min2){
        return max1*max2*max3;
    } else{
        return max1*min1*min2;
    }
}*/
//M2 - 5 iterations for finding max1, max2, max3, min1, min2: O(n)
//M3 - We can implement M2 using only 1 iteration by using Priority Queue data structure (Min Heap and Max Heap)
//Priority Queue in c++, is by default Max Heap
int Solution::maxp3(vector<int> &A) {

    priority_queue <int> mx;//MaxHeap
    priority_queue <int, vector<int>, greater<int> > mn;
    int n = A.size();
    bool hasZero = false;
    int maxElem = INT_MIN;
    for (int i=0; i<n; i++){
        if(A[i] == 0){
            hasZero = true;
            continue;
        }
        if(mn.size()<3){
            mn.push(A[i]);
        } else{
            mn.push(A[i]);
            mn.pop();
        }
        if(mx.size()<2){
            mx.push(A[i]);
        }
        else{
            mx.push(A[i]);
            mx.pop();
        }
        
        maxElem = (maxElem < A[i])? A[i]:maxElem ;
    }
    int cand1 = 1, cand2 = 1;
    while(!mn.empty()){
        cand1 *= mn.top();
        mn.pop();
    }
    while(!mx.empty()){
        cand2 *= mx.top();
        mx.pop();
    }
    cand2 *= maxElem;
    int res = max(cand1, cand2);
    if(hasZero == true){
        res = max(res, 0);
    } return res;
    
}
