#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topoSort(int n, vector <int> adjList[n], vector <int> indegree) {
	queue <int> que;
	// Pushing elements whose indegree is 0
	for (int i=0; i<n; i++) {
		if(indegree[i] == 0) {
			que.push(i);
		}
	}

	while(!que.empty()) {
		int current = que.front();
		que.pop();
		cout<<current;
		// exploring children of popped node and making its indegree 1 lower
		for (int j=0; j<adjList[current].size(); j++) {
			int child = adjList[current][j];
			indegree[child] --;
			// Push the element into the queue if its indegree becomes 0
			if(indegree[child] == 0) {
				que.push(child);
			}
		}
	}
	cout<<endl;
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
	vector <int> indegree(n, 0);
	// adjacency list
	vector <int> adjList[n];
	for (int i=0; i<e; i++) {
		int x, y;
		cin>>x;
		cin>>y;
		adjList[x].push_back(y);
		indegree[y]++;
	}
	topoSort(n, adjList, indegree);
	return 0;
}
