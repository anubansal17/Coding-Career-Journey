#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Approach : To find the number of connected components, we can basically check for the number of times we have to run BFS or DFS from the main function separately
void BFS(int n, int source, vector <int> adjList[n], vector <bool> &visited) {
	// Array to store if a node is visited or not 
	// Making a queue to store all the adjacent nodes
	queue <int> que;
	que.push(source);
	visited[source] = true;
	while(!que.empty()) {
		int current = que.front();
		//cout<<current;
		que.pop();
		for (int j = 0; j < adjList[current].size(); j++) {
			int child = adjList[current][j];
			if(visited[child] == 0) {
				que.push(child);
				visited[child] = true;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	// number of test cases
	int t;
	cin>>t;
	for (int j=0; j<t; j++) {
		// number of vertices
		int n;
		cin>>n;
		int e;
		cin>>e;
		// adjacency list
		vector <int> adjList[n];
		vector <bool> visited(n, 0);
		for (int i=0; i<e; i++) {
			int x, y;
			cin>>x;
			cin>>y;
			adjList[x].push_back(y);
			adjList[y].push_back(x);
		}

		int connectedCom = 0;
		for (int i=0; i<n; i++) {
			if(visited[i] == 0){
				connectedCom++;
				BFS(n, i, adjList, visited);
			}
		}
		cout<<connectedCom<<endl;
	}
	return 0;
}
