// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3387/
class Solution {
    void solve(vector <int> ip, vector<int> op, vector<vector<int>> &ans) {
        // Base condition: If input becomes empty, add its output to ans
        if(ip.empty() == 1) {
            ans.push_back(op);
            return;
        }
        // for any input, we can two kinds of output - Euther we will select the               //  element or not
        // If we aren't selecting the element, output will remain same as previous             // output and input will decrease by 1 element
        vector <int> op1;
        op1 = op;
        // If incase we want to select the element, element will be added in output
        vector <int> op2;
        op2 = op;
        op2.push_back(ip[0]);
        // Removing the first element from input
        ip.erase(ip.begin());
        
        // Calling the recursive function solve for modified ip and op1,op2
        solve(ip,op1,ans);
        solve(ip,op2,ans);
    }
public:
    // By following the recursive tree - Input-Output method
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ip;
        ip = nums;
        vector <int> op;
        // Initially input is our given vector
        solve(ip,op,ans);
        return ans;
    }
};
