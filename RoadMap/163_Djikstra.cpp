#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void djikstra1(int source, int n, vector<vector<int>> adjList[], vector <int> &distance) {
	// Min heap would be used to pop min distance element from the queue always
	priority_queue <pair<int, int>, vector<pair<int, int> >, greater <pair<int, int> > > minHeap;
	// Push source and it's distance pair into minHeap (Having distance as first element and node as second)
	minHeap.push({0, source});
	// Run algo till que is not empty
	while(!minHeap.empty()) {
		// extracting minimum distance having node from heap
		pair <int, int> current = minHeap.top();
		minHeap.pop();
		// If the popped node is already visited, then discard it
		if(distance[current.second] != INT_MAX) {
			continue;
		}
 		// node will be marked as visited at the time of poppping
		// popped distance will be the final minimum distance for this node
		distance[current.second] = current.first; 
		// exploring children of popped element
		for (int i=0; i<adjList[current.second].size(); i++) {
			int childNode = adjList[current.second][i][0];
			// If it is not already visited
			if(distance[childNode] == INT_MAX) {
				int wt = adjList[current.second][i][1];
				minHeap.push({distance[current.second]+wt, childNode});
			    } 
		    }
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
	vector <vector<int> > adjList[n];
	for (int i=0; i<e; i++) {
		int x, y, wt;
		cin>>x;
		cin>>y;
		cin>>wt;
		adjList[x].push_back({y, wt});
	}
	int source = 0;
	// Initialising the distance array with infinity
	vector <int> distance(n, INT_MAX);
	djikstra(source, n, adjList, distance);
	// Making distance of source from source = 0
	distance[source] = 0;
	for (auto num: distance) {
		cout<<num;
	}
	return 0;
}
