/*
1st Approach: Use hash maps(O(n) - T.C and S.C)
2nd Approach: Do negation of the elements present at values of each index
3rd Approach: Hare and Tortoise (Slow and Fast Pointer)
- Initialize fast and slow pointer with first element in the array
- Till the point of collision of fast and slow pointer
- If the slow pointer would have moved a distance a and fast pointer would have moved a distance of 2a
- 
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast =  nums[0];
        int slow = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        // Starting the fast pointer from begining to make it travel distance x
       fast = nums[0];
        // Slow pointer will also travel a distance x till the point of second collision
        while(fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};
