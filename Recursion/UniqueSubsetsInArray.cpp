class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector <int> ip = nums;
        vector <int> op;
        vector <vector <int> > ans;
        set <vector<int>> ansSet;
        solve(ip, op, ansSet);
        for(vector<int> subset: ansSet){
            ans.push_back(subset);
        }
        return ans;
    }
    void solve(vector<int> ip, vector<int> op, set <vector<int> > &ansSet) {
        // Base condition
        if(ip.empty()){
            // Edge case:
            // sorting the subset so that duplicate subsets doesn't come in output
            // For instance- input - 4, 4, 4, 1, 4 will generate duplicate subsets if we don't sort its subsets
            sort(op.begin(), op.end());
            ansSet.insert({op});
            return;
        }
        // We aren't inserting the current element of input in the output
        vector <int> op1 = op;
        // We will be inserting the current element of input into output
        vector <int> op2 = op;
        op2.push_back(ip[0]);
        ip.erase(ip.begin());
        solve(ip, op1, ansSet);
        solve(ip, op2, ansSet);
        return;
    }
};
