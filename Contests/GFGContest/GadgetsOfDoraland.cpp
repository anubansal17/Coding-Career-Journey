// https://practice.geeksforgeeks.org/contest-problem/gadgets-of-doraland/0
#include<iostream>
#include<vector>
#include<unordered_map>
#include<iterator>
#include<algorithm>
using namespace std;

bool cmp(const pair<int, int> &x, const pair<int, int> &y) {
	if(x.second != y.second){
		return x.second > y.second;
	} else {
		return x.first>y.first;
	}
}

int main()
 {
int t, n;
	cin>>t;
	for (int i=0; i<t; i++) {
	    cin>>n;
	    vector <int> d_id(n);
	    for (int j=0; j<n; j++) {
	        int x;
	        cin>>x;
	        d_id[j] = x;
	    }
	    if(n == 1){
	        return d_id[0];
	    }
	    int k;
	    cin>>k;
	    unordered_map<int, int> freq;
	    for (int j=0; j<n; j++) {
	    	freq[d_id[j]] ++;
	    }
	    unordered_map<int, int>::iterator it;
	    it = freq.begin();
	    for (it = freq.begin(); it != freq.end(); it++) {
	    	//cout<<(it->second);
	    }
	    vector < pair<int, int> > mp;
	    for (it = freq.begin(); it != freq.end(); it++) {
	    	mp.push_back(make_pair(it->first, it->second));
	    }
	    sort(mp.begin(), mp.end(), cmp);
	    for (int j=0; j<k; j++) {
	    	cout<<mp[j].first<<" ";
	    }
	    cout<<endl;

	}
	return 0;
}
