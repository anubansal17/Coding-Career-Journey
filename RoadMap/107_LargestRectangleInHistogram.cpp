class Solution {
public:
    vector<int> nextSmallerLeft(vector <int> heights) {
        vector <int> smallerArr;
        stack <pair <int, int>> stk;
        int n = heights.size();
        for(int i=0; i<n; i++) {
            while(!stk.empty() and stk.top().first >= heights[i]) {
                stk.pop();
            }
            if(!stk.empty())
                smallerArr.push_back(stk.top().second);
            else
                smallerArr.push_back(-1);
            stk.push({heights[i], i});
        }
        return smallerArr;
    }
    vector<int> nextSmallerRight(vector <int> heights) {
        vector <int> smallerArr;
        stack <pair <int, int>> stk;
        int n = heights.size();
        for(int i=n-1; i>=0; i--) {
            while(!stk.empty() and stk.top().first >= heights[i]) {
                stk.pop();
            }
            if(!stk.empty())
                smallerArr.push_back(stk.top().second);
            else
                smallerArr.push_back(n);
            stk.push({heights[i], i});
        }
        reverse(smallerArr.begin(), smallerArr.end());
        return smallerArr;
    }
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
        vector<int> left;
        vector<int> right;
        left = nextSmallerLeft(heights);
        right = nextSmallerRight(heights);
        int maxm = INT_MIN;
        vector<int> area;
        for (int i=0; i<n; i++) {
            if(left[i] != -1)
                area.push_back((right[i]-left[i]-1)*heights[i]);
            else
                area.push_back(right[i]*heights[i]);
        }
        for(int i=0;i<n; i++) {
            if(maxm<area[i])
                maxm = area[i];
        }
        return maxm;
    }
};
