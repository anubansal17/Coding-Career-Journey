# Basics
## Number Theory concepts and standard problems
- To find if a number n is a Prime Number:
  - M1 - Run the loop till √n and check if it is divisible by any number
    - Time complexity: O(√n)
  - M2 - Use Sieve approach
- To find all the divisors of a number n
  - Run the loop till √n and check if number n is divisible by element in each iteration
  - If it is divisible by say i, then the number will also be divisible by n/i
  - For instance, Let n = 100
    - We will run loop till √100 = 10
    - As 2 is divisible by 100, we will add this to our answer alongwith adding 100/2 = 50 which is also a divisor of 100
    - Similarly, all of the divisors can be found
    - for the last element that is √n, don't add n/√n. As it will add the number twice in the answer ~ Corner Case
- 
