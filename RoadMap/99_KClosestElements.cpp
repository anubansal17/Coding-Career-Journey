class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Using maxHeap as at the end we need to retain k closest elements in the heap
        priority_queue<pair<int, int>> maxHeap;
        int n = arr.size();
        for (int i=0; i<n; i++) {
            maxHeap.push({abs(x-arr[i]), arr[i]});
            if(maxHeap.size() > k)
                maxHeap.pop();
        }
        vector <int> kClosest;
        for (int i=0; i<k; i++) {
            kClosest.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(kClosest.begin(), kClosest.end());
        return kClosest;
    }
};
