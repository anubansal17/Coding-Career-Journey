# Good to know Concepts behind some standard ques
- To find max consecutive sum in an array:
  - Kadane's Algorithm - Idea behind this algo is to look for all positive segments in the array and keep track of maximum of sum of these segments
    and this maximum sum is our reqd answer
      - Suppose we have array A, having size n. Initialise max = 0 and ans = 0
      - for(int i=0; i<n; i++){
      - max += A[i]
      - if(max<0){max = 0}
      - else if(ans<max) {ans = max}
      - }
      - return ans
- To find max consecutive sum in a circular array containing both positive as well as negative numbers
  - 
