/*
Approach 1: Brute Force: T.C- O(n^2), S.C- O(1)
- For each element check for the highest greater element possible at the right side
Approach 2: T.C- O(n), S.C- O(1)
- Keep track of minimum at the left side
- Calculate the profit while scanning the array from left to right
- Initialise profit as 0, If the profit is greater than change it and if you find any other number lesser than minimum number so far, then update the minimum number
- Atlast, profit at the end will be our answer
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
    }
};
