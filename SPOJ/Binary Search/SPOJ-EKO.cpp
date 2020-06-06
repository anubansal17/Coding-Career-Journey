#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
// Approach: 
// 10 15 17 20
ll findOptimum(vector<ll> treeHeights, ll left, ll right, ll M) {
	ll ans;
	while(left <= right) {
		ll sum = 0;
		ll mid = left + (right-left)/2;
		for (ll i=0; i<treeHeights.size(); i++) {
			if(mid <= treeHeights[i])
				sum += treeHeights[i] - mid;
			//cout<<sum;
		}
		//cout<<endl;
		if(sum >= M) {
			//cout<<mid;
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	//cout<<ans;
	return ans;
}
int main() {
	ll k;
	cin>>k;
	ll M;
	cin>>M;
	vector <ll> treeHeights;
	for (ll i=0; i<k; i++) {
		ll x;
		cin>>x;
		treeHeights.push_back(x);
	}
	ll maxh = -1;
	for (ll i=0; i<k; i++) {
		maxh = max(treeHeights[i], maxh);
	}
	//cout<<endl;
	cout<<findOptimum(treeHeights, 0, maxh, M);

	return 0;
}