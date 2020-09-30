/*
- Approach 1: Brute force: O(n^2)
- Approach 2: Naive approach: Use hash maps and track the frequency T.C- O(n) and S.C- O(n)
- Approach 3: Moore's Voting Algo T.C- O(n) and S.C - O(1)
- If number is a majority element its occuerences would be more than n/2
- It will cancel out the occurences for all the other non-majority eloements
- Use this idea, to find out the majority element
*/
// Approach 3: Implementation
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //map <int, int> mp;
        int n = nums.size();
        int count = 1;
        int curNum = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] == curNum){
                count ++;
            } else{
                if(count == 0){
                    curNum = nums[i];
                    count = 1;
                } else{
                    count --;
                }
            }
        }
        return curNum;
    }
};
