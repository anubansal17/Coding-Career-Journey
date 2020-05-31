// https://leetcode.com/problems/subsets/
class Solution {
    vector<vector<int>> ans;
    void recurse(int index, vector <int> nums, vector <int> subset) {
        if(index == nums.size()) {
            ans.push_back(subset);
            return;
        }
        recurse(index+1, nums, subset);
        subset.push_back(nums[index]);
        recurse(index+1, nums, subset);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> subset{};
        //adding empty subset at index 0
        recurse(0, nums, subset);
        return ans;
    }
};
