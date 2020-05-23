// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3338/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int m = B.size();
        int len = min(n, m);
        vector <vector<int>> ans;
        if (n == 0 or m == 0){
            return ans;
        }
        
        for (int i=0,j=0; i<n and j<m;){
           if(max(A[i][0],B[j][0]) <= min(A[i][1], B[j][1])){
                ans.push_back({max(A[i][0],B[j][0]), min(A[i][1], B[j][1])});
            }
            if(A[i][1]>B[j][1]){
               j++;
           }else{
               i++;
           }
            
            
        }
        return ans;
    }
};
