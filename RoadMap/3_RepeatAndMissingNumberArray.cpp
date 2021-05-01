/*
Approach1: O(n) - T.C and S.C
- To find the repeated number in the array, 
- Use a boolean vector of same size
- To find the missing number use below formula
exSum = n*(n+1)/2 = p;
actualSum
exSum - missing + dup = actualSum
miss + dup = actualSum - exSum

Approach 2: T.C - O(n) and S.C - O(1)
expectedSum - ActualSum = missing - dupl
(1^2+2^2+---+n^2) - Sum(Actual Squares) = missing^2 - dupl^2
=> (expectedSum-ActualSum)(missing + dupl)

Approach 3: Using XOR
*/

// Approach 1 Implementation
vector<int> Solution::repeatedNumber(const vector<int> &A) {
   int n = A.size();
   int dupl;
   long long int acSum = 0;
   // Finding the duplicate number
   vector <bool> arr(n, 0);
   for (int i=0; i<n; i++) {
       acSum += A[i];
       if(arr[A[i]] != 0) {
           dupl = A[i];
       } else {
           arr[A[i]] = 1;
       }
   }
   
   // Finding the missing number
   long long int exSum = (long long)n*(long long)(n+1)/2;
   int miss;
   miss = (long long)exSum - (long long)acSum + dupl;
   vector<int> ans;
   ans.push_back(dupl);
   ans.push_back(miss);
   return ans;
}
// Approach2 Implementation
// Using xor
vector<int> Solution::repeatedNumber(const vector<int> &V) {
    long long  sum = 0;
    long long sum2 = 0;
    int n = V.size();
    long long int temp;
    for (int i=0; i<n; i++) {
        temp = V[i];
        sum += V[i];
        sum -= (i+1);
        sum2 += (long long)(V[i])*(long long)(V[i]);
        sum2 -= (long long)(i+1)*(long long)(i+1);
    }
    // Rep - Miss = sum
    // Rep^2 - Miss^2 = sum2
    // Rep + Miss = sum2/sum
    // Rep - Miss = sum
    // 2Rep = (sum2/sum) + sum
    // Rep = ((sum2/sum) + sum)/2
    sum2 /= sum;
    int x = (int)((sum2 + sum)/2);
    int y = x - sum;
    vector <int> ans;
    ans.push_back(x);
    ans.push_back(y);
    return ans;
}


// Approach 3 Implementation
// Using xor
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Dupl^missing
    int n = A.size();
    int aXor = A[0];
    for (int i=1; i<n; i++) {
        aXor ^= A[i];
    }
    int eXor = 1;
    for (int i=2; i<=n; i++) {
        eXor ^= i;
    }
    int pos = -1;
    // dupl^miss = comb => aXor^eXor
    int comb = aXor^eXor;
    // first set bit in comb
    for(int i=0; i<n; i++){
        // left shift comb by i
        if((comb>>i) &1){
            pos = i;
            break;
        }
    }
    // bucket of elements which have pos as 1
    int x = 0;
    int y = 0;
    for (int num : A) {
        if((num>>pos)&1) {
            x ^= num;
        }else{
            y ^= num;
        }
    }
    for(int i=1; i<=n; i++){
        if((i>>pos)&1){
            x ^= i;
        }else {
            y ^= i;
        }
    }
    vector<int> ans;
    for(int i=0; i<n; i++) {
        if(A[i] == x){
            ans.push_back(x);
            ans.push_back(y); 
            break;
        } else if(A[i] == y) {
            ans.push_back(y);
            ans.push_back(x); 
            break; 
        }
    }
    return ans;
}

