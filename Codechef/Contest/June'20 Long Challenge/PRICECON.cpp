// https://www.codechef.com/JUNE20B/submit/PRICECON
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	for (int i=0; i<t; i++) {
	    int N;
	    int k;
	    cin>>N;
	    cin>>k;
	    vector <int> price(N);
	    for (int j=0; j<N; j++) {
	        int x;
	        cin>>x;
	        price[j] = x;
	    }
	    int ans = 0;
	    for (int j=0; j<N; j++) {
	        if(price[j] > k) {
	            ans += price[j] - k;
	        }
	    }
	    cout <<ans<<endl;
	}
	return 0;
}
