#include<iostream>
#include<vector>
using namespace std;
// DSU optimization using rank and path compression
class DisjointSet {
	int *rank, *parent, n;
public:
	// Constructor
	DisjointSet(int n){
		rank = new int[n];
		parent = new int[n];
		this->n = n;
		// Making individual groups for all elements
		makeSet();
	}
	void makeSet() {
		for (int i=0; i<n; i++) {
			parent[i] = i;
		}
	}

	// Finds extreme parent for any element
	int findSet(int x) {
		if(parent[x] == x) {
			return x;
			}
		int par = findSet(parent[x]);
		// Storing the parent in parent array for further reference (to avoid further fxn calls)
		// Path Compression Optimization
		parent[x] = par; 
		return par;
	}

	// Unites two groups having these two elements
	void Union(int x, int y) {
		int parX = findSet(x);
		int parY = findSet(y);
		// If both are in same group already
		if(parX == parY) {
			return;
			}
		// Set one as a child for other
		// Compare ranks for both, whichever has lesser rank would serve as a child for other one
		// Union by rank Optimization
		if(rank[parX] > rank[parY]) {
			parent[parY] = parX;
		} else if (rank[parY] > rank[parX]) {
			parent[parX] = parY;
			}
		// If ranks of both are same, anyone can become child of other one
		// Also, rank will get incremented by 1 for the parent
		else {
			parent[parY] = parX;
			rank[parX] ++;
		}
	}
};

	int main() {
		DisjointSet obj(7);
		obj.Union(0,1);
		obj.Union(1,2);
		obj.Union(4,5);
		obj.Union(2,3);
		obj.Union(3,4);
		obj.Union(1,6);
		for (int i=0; i<7; i++) {
			cout<<obj.findSet(i);
		}
		return 0;
}