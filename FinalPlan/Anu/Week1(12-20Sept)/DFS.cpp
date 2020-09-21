#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Sample Input
/*
6
0 1              
0 3
1 2
1 6
3 4
3 5
*/
// Sample Output
/*
Printing the adjacency list
0->1 3 
1->2 6 
2->
3->4 5 
4->
5->
0 1 2 6 3 4 5 
*/
// Adjacency list to store graph
vector <int> v[7];
bool visited[7] = {false};

void adjacencyList(int n) {
	for (int i=0; i<n; i++) {
		int x, y;
		// Edge from x to y
		cin>>x>>y;
		// storing the edges for x (outdegree)
		v[x].push_back(y);
	}
	// Printing the adjacency list
	cout<<"Printing the adjacency list"<<endl;
	for (int i=0; i<n; i++){
		cout<<i<<"->";
		for (int j=0; j<v[i].size(); j++) {
			cout<<v[i][j]<<" ";
		}
		cout <<endl;
	}
}
void DFS(int x) {
	int current = x;
	visited[x] = true;
	cout<<current<<" ";
	// Base condition: If the current node doesn't have any adjacent nodes(outdegree nodes)
	if(v[current].size() == 0) {
		return;
	}
	// The control will go to the point from where the function was called(which is inside the for loop in our case)
	for (int i=0; i<v[current].size(); i++) {
		int adjacent = v[current][i];
		// If the adjacent node is not visited
		if(visited[adjacent] == false) {
			DFS(adjacent);
		}
	}
	// Exploring the adjacent node
}
int main() {
	int n;
	cout<<"enter no. of edges"<<endl;
	cin>>n;
	adjacencyList(n);
	// DFS traversal
	// To make sure that we are visiting every node
	// As if we start with a node which is having outdegree as 0
	// In that case, we won't be traversing the whole graph if we don't check for this condition
	// If all the nodes are visited or nor
	for (int i=0; i<n; i++) {
		if(visited[i] == false) {
			DFS(i);
		}
	}
	return 0;
}
