// Approach1- Using minheap
// T.C - O(nlogk) S.C- O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();

        priority_queue <int, vector<int>, greater<int>> minh;
        for (auto num : nums) {
            // push element into heap
            minh.push(num);
            // If size of heap becomes greater than k, pop from it
            if(minh.size() > k) {
                minh.pop();
            }
        }
        // At the end, the top element in my heap would be the kth largest element
        int ans = minh.top();
        return ans;
    }
};
