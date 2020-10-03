/*
Approach 1: Using Hashing T.C- O(N), S.C- O(N)
- Put all the elements in a set
- for each element, check if one lesser element exists in the hash set or not,  if it does exist then do nothing
- If it doesn't exist, check if one greter element exists or not and keep checking till the we get this sequence of consecutive numbers in increasing order
- the point where it breaks, consider it as the length of current consecutive sequence and check if it is greater than the already set max consecutive length
- this keeps going
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> elementSet;
        for (auto num: nums) {
            elementSet.insert({num});
        }
        int maxLength = 0;
        for (auto num: nums) {
            int curLength = 0;
            // If one lesser element doesn't exist
            if(elementSet.find(num-1) == elementSet.end()) {
                while(elementSet.find(num) != elementSet.end()) {
                    curLength++;
                    num ++;
                }
            }
            if(curLength > maxLength){
                maxLength = curLength;
            }
        }
        return maxLength;
    }
};
