#include <iostream>
#include <vector>
using namespace std;

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
	cout<<"no of vertices";
	cin>>n;
	cout<<"no of edges";
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
	return 0;
}
