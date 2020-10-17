#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int n, int source, vector <int> adjList[n], vector <bool> &visited) {
	// Array to store if a node is visited or not 
	// Making a queue to store all the adjacent nodes
	queue <int> que;
	que.push(source);
	visited[source] = true;
	while(!que.empty()) {
		int current = que.front();
		cout<<current;
		que.pop();
		for (int j = 0; j s< adjList[current].size(); j++) {
			int child = adjList[current][j];
			if(visited[child] == 0) {
				que.push(child);
				visited[child] = true;
			}
		}
	}
}

void printAdj(int n, vector<int> adjList[n]) {
	for (int i=0; i<n; i++) {
		cout<<i<<"->";
		for (int j = 0; j < adjList[i].size(); j++) {
			cout<<adjList[i][j];
		}
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	// number of vertices
	int n;
	cout<<"no of vertices ";
	cin>>n;
	cout<<"no of edges ";
	int e;
	cin>>e;
	// adjacency list
	vector <int> adjList[n];
	for (int i=0; i<e; i++) {
		int x, y;
		cin>>x;
		cin>>y;
		adjList[x].push_back(y);
	}
	printAdj(n, adjList);
	for (int i=0; i<n; i++) {
		if(visited[i] == 0)
			BFS(n, i, adjList, visited);
	}
	return 0;
}
