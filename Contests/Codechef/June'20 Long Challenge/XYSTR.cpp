// https://www.codechef.com/JUNE20B/submit/XYSTR
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	for (int i=0; i<t; i++) {
	    string s;
	    cin>>s;
	    int ans = 0;
	    int n = s.size();
	    for (int i=0; i<n-1; i++) {
	       if(s[i] == 'x' and s[i+1] == 'y') {
	              ans ++;
	              i ++;
	       } else if(s[i] == 'y' and s[i+1] == 'x') {
	           ans ++;
	           i ++;
	       }
	    }
	    cout <<ans<<endl;
	}
	return 0;
}
