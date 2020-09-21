#include<iostream>
#include<vector>
using namespace std;
// Sample Input:
/*
0 2
1 3
2 4
2 1
4 1
*/
// Sample Output:
/*
0->2 
1->3 
2->4 1 
3->
4->1
*/
void adjacencyList(int n) {
	// Adjacency list to store graph
	vector <int> v[n];
	for (int i=0; i<n; i++) {
		int x, y;
		// Edge from x to y
		cin>>x>>y;
		// storing the edges for x (outdegree)
		v[x].push_back(y);
	}
	// Printing the adjacency list
	for (int i=0; i<n; i++){
		cout<<i<<"->";
		for (int j=0; j<v[i].size(); j++) {
			cout<<v[i][j]<<" ";
		}
		cout <<endl;
	}
}
int main() {
	// No. of nodes in graph
	int n;
	cin>>n;
	adjacencyList(n);
	return 0;
}
