// Time complexity: O(V+E)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Adjacency list to store graph
vector <int> v[5];
bool visited[5] = {false};

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
void BFS(int source) {
	queue <int> que;
	// Putting element in queue
	que.push(source);
	// marking it as visited
	visited[source] = true;
	// Pushing the adjacent elements to queue
	while(!que.empty()) {
		int current = que.front();
		que.pop();
		cout<<current<<" ";
		for (int i=0; i<v[current].size();i++) {
			int adjacent = v[current][i];
			// Check if adjacent node is already visited or not
			if(visited[adjacent] == false) {
				que.push(adjacent);
				visited[adjacent] = true;
			}
		}
	}
	cout<<endl;
}
int main() {
	int n = 5;
	adjacencyList(n);
	// BFS traversal
	// To make sure that we are visiting every node
	// As if we start with a node which is having outdegree as 0
	// In that case, we won't be traversing the whole graph if we don't check for this condition
	// If all the nodes are visited or nor
	for (int i=0; i<n; i++) {
		if(visited[i] == false) {
			BFS(i);
		}
	}
	return 0;
}
