# Basics
# Standard Problems:
- To find the xor of all elements from i to j in an array A:
  - Maintain an extra array B and store xor of elements till i at index i in this new array B
  - To return the answer, do B[j]^B[i]
  - Time complexity of giving the answer is O(1) which is really helpful incase we have to find the answer for n queries
  - It reduces the complexity of the solution to O(n)
