# Basics
# Tricks for Standard Problems:
- To find the xor of all elements from i to j in an array A:
  - Maintain an extra array B and store xor of elements till i at index i in this new array B
  - To return the answer, do B[j]^B[i]
  - Time complexity of giving the answer is O(1) which is really helpful incase we have to find the answer for n queries
  - It reduces the complexity of the solution to O(n)
- To find if number is a power of 2 or not:
  - Do 'and' of n and n-1 if it is equal to zero than it is a power of 2 otherwise not.
    Example: 8: 1000, 7 : 0111 so 8&7 == 0 which implies 8 is a power of 2

