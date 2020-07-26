#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int LCS(string s1, string s2, int n, int m) {
    int tp[n+1][m+1];
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            // If anyone of string is empty - common substring length would be 0
            if(i == 0 or j == 0) {
                tp[i][j] = 0;
            }
            // If current chars at both the strings are equal, we would increase the continuous length 
            else if(s1[i-1] == s2[j-1]) {
                tp[i][j] = tp[i-1][j-1] + 1;
            } 
            // Else if both the chars are not equal, we would break the continuity and make the length as 0
            else {
                tp[i][j]  = 0;
            }
        }
    }
    // Answer shud be the max common substring length present
    // Return max value present in the matrix
    int max = INT_MIN;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            if(tp[i][j] > max) {
                max = tp[i][j];
            }
        }
    }
    return max;
}
int main()
 {
int T, n;
	cin>>T;
	for (int i=0; i<T; i++)
	{
	    int n;
	    int m;
	    string s1;
	    string s2;
	    cin>>n>>m;
	    cin>>s1>>s2;
	    int ans;
	    ans = LCS(s1, s2, n, m);
	    cout<<ans<<endl;
	}
	return 0;
}
