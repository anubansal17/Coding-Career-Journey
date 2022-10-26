**Leetcode 1842. Next Palindrome Using Same Digits**
Hard

You are given a numeric string num, representing a very large palindrome.

Return the smallest palindrome larger than num that can be created by rearranging its digits. If no such palindrome exists, return an empty string "".

A palindrome is a number that reads the same backward as forward.

Example 1:

Input: num = "1221"
Output: "2112"
Explanation: The next palindrome larger than "1221" is "2112".

Example 2:

Input: num = "32123"
Output: ""
Explanation: No palindromes larger than "32123" can be made by rearranging the digits.

Example 3:

Input: num = "45544554"
Output: "54455445"
Explanation: The next palindrome larger than "45544554" is "54455445".

**1428. Leftmost Column with at Least a One**
Medium

A row-sorted binary matrix means that all elements are 0 or 1 and each row of the matrix is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return the index (0-indexed) of the leftmost column with a 1 in it. If such an index does not exist, return -1.

You can't access the Binary Matrix directly. You may only access the matrix using a BinaryMatrix interface:

    BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
    BinaryMatrix.dimensions() returns the dimensions of the matrix as a list of 2 elements [rows, cols], which means the matrix is rows x cols.

Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes, the input will be the entire binary matrix mat. You will not have access to the binary matrix directly.

Example 1:

Input: mat = [[0,0],[1,1]]
Output: 0

Example 2:

Input: mat = [[0,0],[0,1]]
Output: 1

Example 3:

Input: mat = [[0,0],[0,0]]
Output: -1

