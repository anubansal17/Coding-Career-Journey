#include<iostream>
using namespace std;
int LCS(string s1, string s2, int n, int m) {
        int tp[n+1][m+1];
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=m; j++) {
               // Base condition
                if(i == 0 or j == 0)
                    tp[i][j] = 0;
                // If elements at current indexes of both the strings are equal
                else if(s1[i-1] == s2[j-1] && i != j) {
                    tp[i][j] = 1+tp[i-1][j-1];
                } else {
                    tp[i][j] = max(tp[i][j-1], tp[i-1][j]);
                } 
            }
        }
    return tp[n][m];
}
int main()
 {
int T, n;
	cin>>T;
	for (int i=0; i<T; i++)
	{
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    // For LRS - We just need to find the LCS s.t. indexes are not same but the chars are same
	    int ans = LCS(s, s, n, n);
	    cout<<ans<<endl;
	}
	return 0;
}
