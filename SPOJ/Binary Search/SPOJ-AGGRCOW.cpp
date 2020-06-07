#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isValidDistance (vector <int> stalls, int dist,int C) {
	C--;
	int prevStall = stalls[0];
	for(int i=1; i< stalls.size(); i++) {
		if((stalls[i]-prevStall) >= dist) {
			C--;
			prevStall = stalls[i];
		}
		if(C == 0){
		return 1;
	}
	}
	
	return 0;
}
int searchMaxDistance(vector <int> stalls, int left, int right, int C) {
	int mid;
	int ans;
	while(left <= right) {
		mid = left + (right-left)/2;
		if(isValidDistance(stalls, mid, C)) {
			ans = mid;
			left = mid+1;
		} else {
			right = mid - 1;
		}
	}
	return ans;
}
int main() {
	int t;
	cin>>t;
	for (int i=0; i<t; i++) {
		int N;
		int C;
		cin>>N;
		cin>>C;
		int ans;
		vector <int> stalls(N);
		for (int j=0; j<N; j++) {
			int x;
			cin>>x;
			stalls[j] = x;
		}
		sort(stalls.begin(), stalls.end());
		ans = searchMaxDistance(stalls, stalls[0], stalls[N-1]-stalls[0], C);
		cout<<ans<<endl;
	}
	return 0;
}