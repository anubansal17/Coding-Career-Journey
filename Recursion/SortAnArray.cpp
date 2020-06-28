// Time Complexity of recursive solution is more than O(nlogn) - Not preferable for sorting
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
       int n = nums.size();
        if(nums.size() == 1){
           return nums;
       }
        int temp = nums[n-1];
        nums.pop_back();
        sortArray(nums);
        // inserting the element present in temp to nums vector
        insert(nums, temp);
        return nums;
    }
    void insert(vector <int> &nums, int temp) {
        if(nums.size() == 0 or nums[nums.size()-1] <= temp) {
            nums.push_back(temp);
            return;
        }
        // We are taking backup of the value which is greater than temp
        int val = nums[nums.size()-1];
        // We are removing the elements that are greater than temp
        nums.pop_back();
        insert(nums, temp);
        // Putting back all the elements which are greater than temp
        nums.push_back(val);
    }
};
