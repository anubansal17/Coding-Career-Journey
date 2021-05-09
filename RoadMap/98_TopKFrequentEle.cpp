typedef pair<int, int> pi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector <int> kTop;
        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
        }
        priority_queue<pi, vector<pi>, greater<pi>> minHeap;
        for (auto it : mp) {
            minHeap.push({it.second, it.first});
            if(minHeap.size() > k)
                minHeap.pop();
        }
        for (int i=0; i<k; i++) {
            kTop.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return kTop;
    }
};
