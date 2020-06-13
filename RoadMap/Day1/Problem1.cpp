class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare = nums[0];
        int tor = nums[0];
        do {
            tor = nums[tor];
            hare = nums[nums[hare]];
        }while (tor != hare);
        
        // Phase2
        tor = nums[0];
        while(tor != hare) {
            tor = nums[tor];
            hare = nums[hare];
        }
        return tor;
    }
};
