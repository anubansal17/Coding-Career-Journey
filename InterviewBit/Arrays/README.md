# Good to know concepts behind some standard ques
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
  - We have 3 cases to consider:
    - Case 1: If all elements in the array are negative
      - Run a loop and check the largest element in the array and return it
    - Case 2: If max sum exists in the inner part of the array alongwith one of the corner element
      - Run the Kadane's Algo without any changes in the array
    - Case 3: If max sum exists, including both the corner elements i.e., wrapping is there
      - Find total sum of all the elements in the array and subtract sum of non-contributing elements from it
      - To find the sum of non contributing elements, invert the sign of each element in the array and run kadane's Algo for 
        this array and result from this algo would be the sum of non contributing elements(sum is with opposite sign)
      - Reqd answer = totalSum - (- nonContriSum)
## Sets
- Also stores the elements in sorted order(Talking about ordered sets)
- Unordered maps store the elements in unsorted order
- Time complexity of doing operations in sets is same as that for maps
- For accessing value at any key, the syntax is *iterator

