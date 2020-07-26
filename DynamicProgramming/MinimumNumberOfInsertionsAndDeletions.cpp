#include<iostream>
using namespace std;
int LCS(string str1, string str2, int n, int m) {
        int tp[n+1][m+1];
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=m; j++) {
                if(i == 0 or j == 0) {
                    tp[i][j] = 0;
                }
                // if chars at both the current indices are equal
                else if(str1[i-1] == str2[j-1]) {
                    tp[i][j] = 1 + tp[i-1][j-1];
                } else {
                    tp[i][j] = max(tp[i-1][j], tp[i][j-1]);
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
	   int n, m;
	   cin>>n>>m;
	   string s1, s2;
	   cin>>s1>>s2;
	   int clen = LCS(s1, s2, n, m);
	   
	   int ans = n - clen + m - clen;
	   cout<<ans<<endl;
	}
	return 0;
}
