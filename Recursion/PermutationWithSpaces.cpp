#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(string ip, string op, vector <string> &ans) {
    // Base condition
    if(ip == ""){
        ans.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back(ip[0]);
    op2.push_back(' ');
    op2.push_back(ip[0]);
    ip.erase(ip.begin());
    solve(ip, op1, ans);
    solve(ip, op2, ans);
    return;
}
int main()
 {
int T, n;
	cin>>T;
	for (int i=0; i<T; i++)
	{
	   string ip;
	   cin>>ip;
	   string op;
	   op.push_back(ip[0]);
	   ip.erase(ip.begin());
	   vector <string> ans;
	   solve(ip, op, ans);
	   sort(ans.begin(), ans.end());
	   for(string perm: ans){
	       cout<<"("<<perm<<")";
	   }
	   cout<<endl;
	}
	return 0;
}
