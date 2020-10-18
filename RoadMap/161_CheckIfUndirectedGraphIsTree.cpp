#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
To check if any given undirected graph is a tree or not, there are 3 conditions
1. no of edges = no of vertices - 1 and the graph is connected
2. no cycle exists
3. edges are bidirectional
- If in a disconnected graph, number of edges = no of vertices - 1 then when we will check for cycle thing, it will return true as cycle would be there
- If graph is disconnested and edges are less than n-1, then it will return false as it is not a tree
*/
bool DFS(int n, vector<int> adjList[n+1], vector <bool> &visited, int source, int parent) {
        visited[source] = true;
        for (int j=0; j<adjList[source].size(); j++) {
            int child = adjList[source][j];
            // If child is already visited and it's not equal to parent
            if(visited[child] == 1 && child != parent)
                return true;
            // If child is not visited then call DFS for child
            else if(visited[child] == 0) {
                if(DFS(n, adjList, visited, child, source) == true) {
                    return true;
                }   
            }
        }
    return false;
}

bool isGraphATree(int n, vector<int> adjList[n+1]) {
	vector <bool> visited(n, false);
	bool isCyclic = false;
    for (int i=1; i<=n; i++) {
        if(visited[i] == 0) {
          isCyclic = DFS(n, adjList, visited, i, -1);
          if(isCyclic == true)
              return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
	// number of vertices
	int n;
	cin>>n;
	int e;
	cin>>e;
	bool isTree;
	// adjacency list
	vector <int> adjList[n+1];
	for (int i=0; i<e; i++) {
		int x, y;
		cin>>x;
		cin>>y;
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}
	// Checking if number of edges are equal to n-1 or not
	// If edges != n-1, return false. No need to check further
	if(e != n-1) {
		cout<<"NO";
		return 0;
	}
	isTree = isGraphATree(n, adjList);
	isTree ? cout<<"YES": cout<<"NO";
	return 0;
}
