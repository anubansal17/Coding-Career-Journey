void swap(int i, int j, vector <int> &nums){
    int temp = nums[j];
    nums[j] = nums[i];
    nums[i] = temp;
}
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int mid = 0;
        int right = n-1;
        while(mid <= right) {
            if(nums[mid] == 0) {
               swap(mid,left,nums);
                left ++;
                mid ++;
            }
            else if(nums[mid] == 1){
                mid ++;
            }
            else{
                swap (mid, right, nums);
                right --;
                
            }
        }
    }
};
