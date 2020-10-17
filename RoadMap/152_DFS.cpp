#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int n, int source, vector<int> adjList[n], vector <bool> &visited) {
		int current = source;
		visited[source] = true;
		cout<<source;
		for (int j=0; j<adjList[source].size(); j++) {
			int child = adjList[source][j];
			if(visited[child] == 0) {
				DFS(n, child, adjList, visited);
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
			DFS(n, i, adjList, visited);
	}
	return 0;
}
