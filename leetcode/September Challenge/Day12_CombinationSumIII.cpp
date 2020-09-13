// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3457/
// As maximum subsets possible are only 512, we can proceed with the brute force approach of finding all the subsets without exceeding the time limit
class Solution {
    void solve(vector <int> ip, vector<int> op, set<vector<int>> &ansSet, int k) {
        // Base condition: If input becomes empty, add its output to ans
        if(ip.empty() == 1) {
            if(op.size() == k) {
                sort(op.begin(), op.end());
                ansSet.insert({op});
            }
            return;
        }
        // for any input, we can two kinds of output - Euther we will select the element or not
        // If we aren't selecting the element, output will remain same as previous output and input             will decrease by 1 element
        vector <int> op1;
        op1 = op;
        // If incase we want to select the element, element will be added in output
        vector <int> op2;
        op2 = op;
        op2.push_back(ip[0]);
        // Removing the first element from input
        ip.erase(ip.begin());
        
        // Calling the recursive function solve for modified ip and op1,op2
        solve(ip,op1,ansSet, k);
        solve(ip,op2,ansSet, k);
    }
    vector<vector<int>> subsets(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        vector<int> ip;
        ip = nums;
        vector <int> op;
        // Initially input is our given vector
        set <vector<int>> ansSet;
        solve(ip, op, ansSet, k);
        for(vector<int> subset: ansSet){
            ans.push_back(subset);
        }
        return ans;
    }
// By following the recursive tree - Input-Output method
public:
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<int> v = {1,2,3,4,5,6,7,8,9};
        // finding all the subsets of length k
        vector<vector<int>> ansTemp;
        vector<vector<int>> ans;
        ansTemp = subsets(v, k);
        cout<<ansTemp.size();
        int size = ansTemp.size();
        for(int i=0; i<size; i++) {
            int sum = 0;
            for(int j=0; j<ansTemp[i].size(); j++) {
                sum += ansTemp[i][j];
            }
            if(sum == n) {
                ans.push_back(ansTemp[i]);
            }
        }
        return ans;
    }
};
