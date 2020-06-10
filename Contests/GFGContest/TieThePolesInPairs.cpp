// https://practice.geeksforgeeks.org/contest-problem/tie-the-poles-in-pairs/0
#include <iostream>
using namespace std;

long long int dp[2600];
long long int findWays()
{
dp[0] = dp[1] = 1;
for (int i=2; i<=2505; i++)
{
    dp[i] = 0;
    for (int j=0; j<i; j++)
        dp[i] = (dp[i] + (dp[j] * dp[i-j-1])%1000000007)%1000000007;
}

}

int main()
{
    int t,n;

    findWays();
    cin >> t;
    while(t--){
        cin >> n;
        cout << dp[n]%1000000007<<endl;
    }
    return 0;
}
