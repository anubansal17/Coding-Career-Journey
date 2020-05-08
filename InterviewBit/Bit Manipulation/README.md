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
- To find if the nth bit is set or unset in a number N
  - Right shift number by n and then & this with 1 if it is 0 then the bit is unset and if it is 1 then it is set
  - To find total no of bits in N, use ceil(log(N)) or we can use predefined function which is __builtin_popcount(N)   
    it will return the number of set bits in number N
- To find all the subsets of elements present in an array:
  - Find total number of subsets possible - 2^(no. of elements)
  - Binary representation of all the numbers from 0 to (2^(n) - 1) represents all the subsets
  - For instance, let's say we have array A = [1, 2, 3]
  - N = 3, no. of subsets = 8
  - 000 represents empty set
  - 001 represents [3]
  - 010 represents [2]
  - 011 represents [2,3]
  - 100 represents [1]
  - 101 represents [1,3]
  - 110 represents [1, 2]
  - 111 represents [1,2,3]
  - As we can see, all the possible subsets have been covered this way
- 

