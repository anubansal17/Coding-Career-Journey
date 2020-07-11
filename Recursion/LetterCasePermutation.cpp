class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector <string> ans;
        string op = "";
        solve(S, op, ans);
        return ans;
    }
    void solve(string ip, string op, vector<string> &ans) {
        // Base condition
        if(ip == ""){
            ans.push_back(op);
            return;
        }
        //If the current input character is an alphabet
        if(isalpha(ip[0])) {
            string op1 = op;
            string op2 = op;
            op1.push_back(tolower(ip[0]));
            op2.push_back(toupper(ip[0]));
            ip.erase(ip.begin());
            solve(ip, op1, ans);
            solve(ip, op2, ans);
            return ;
        }
        else {
            string op1 = op;
            op1.push_back(ip[0]);
            ip.erase(ip.begin());
            solve(ip, op1, ans);
        }
    }
};
