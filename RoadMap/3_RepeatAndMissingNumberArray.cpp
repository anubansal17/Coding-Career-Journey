/*
Approach1: O(n) - T.C and S.C
- To find the repeated number in the array, 
- Use a boolean vector of same size
- To find the missing number use below formula
exSum = n*(n+1)/2 = p;
actualSum
exSum - missing + dup = actualSum
miss + dup = actualSum - exSum

Approach 2: expectedSum - ActualSum = missing - dupl
(1^2+2^2+---+n^2) - Sum(Actual Squares) = missing^2 - dupl^2
=> (expectedSum-ActualSum)(missing + dupl)
*/
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
