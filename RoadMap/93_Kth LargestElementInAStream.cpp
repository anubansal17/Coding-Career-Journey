/*
Approach 1: Make the array sorted and find kth largest element in the array
- When new element comes in, check if it is smaller than the kth largest elemet or greater
- If it is smaller then ignore
- If it is larger then remove the smallest element from array and insert it in sorted array
- change the kth largest element accordingly
- T.C- for processing new element - O(k)
Approach 2: Use min heap
- Maintain a min heap of size k while initialising the array
- Keep on pushing into the heap until size of heap becomes greater than k
- If size of heap exceeds k, then pop the top 
- On getting any new element from the stream, push it on heap and pop the top
- top of the heap is kth largest element
*/

class KthLargest {
public:
priority_queue <int, vector<int>, greater<int>> minh;
int heapSize;
    KthLargest(int k, vector<int>& nums) {
        heapSize = k;
        for (auto num: nums) {
            minh.push(num);
            if(minh.size() > k) {
                minh.pop();
            }
        }
    }
    
    int add(int val) {
        minh.push(val);
        if(minh.size() > heapSize) {
                minh.pop();
            }
        return minh.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
