class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int d = n2-n1;
        int end = n2;
        stack <int> numStack;
        vector <int> ans;
        for (int i=n2-1; i >= 0; i--) {
            if(numStack.empty()) {
                ans.push_back(-1);
            } else {
               if(numStack.top() > nums2[i]) {
                    ans.push_back(numStack.top());
                }  else{
                     while(!numStack.empty()) {
                         if(numStack.top() > nums2[i]) {
                             ans.push_back(numStack.top());
                             break;
                         }
                          numStack.pop();
                     }
                     if(numStack.empty()) {
                         ans.push_back(-1);
                     }
                }  
            }
            numStack.push(nums2[i]);
        }
    unordered_map <int, int> ansMap;
    reverse(ans.begin(), ans.end());
    for(int i=0; i<n2; i++) {
        ansMap.insert({nums2[i], ans[i]});
    }
        vector <int> finalAns(n1);
    for(int i=0; i<n1; i++) {
        finalAns[i] = ansMap[nums1[i]];
    }
    return finalAns;
    }
};
