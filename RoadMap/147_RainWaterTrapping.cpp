class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector <int> rightMax(n, 0);
        for (int i=n-2; i>=0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i+1]);
        }
        int waterTrapped = 0;
        int leftMax = 0;
        for (int i=1; i<n-1; i++) {
            leftMax = max(leftMax, height[i-1]);
            int temp = min(leftMax, rightMax[i]) - height[i];
            if(temp > 0) {
                waterTrapped += temp;
            }
        }
        return waterTrapped;
    }
};
