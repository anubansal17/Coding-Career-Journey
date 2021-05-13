class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector <int> maxLeft(n, 0);
        vector <int> maxRight(n, 0);
        for (int i=1; i<n; i++) {
            maxLeft[i] = max(maxLeft[i-1], height[i-1]);
        }
        int waterTrapped = 0;
        for (int i=n-2; i>=0; i--) {
            maxRight[i] = max(maxRight[i+1], height[i+1]);
            waterTrapped += max(min(maxRight[i], maxLeft[i]) - height[i], 0);
        }
        return waterTrapped;
    }
};
