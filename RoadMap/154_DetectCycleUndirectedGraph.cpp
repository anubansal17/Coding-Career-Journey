// Approach: Using DFS
bool DFS(vector<vector<int>> &adjList, vector <bool> &visited, int source, int parent) {
        visited[source] = true;
        for (int j=0; j<adjList[source].size(); j++) {
            int child = adjList[source][j];
            // If child is already visited and it's not equal to parent
            if(visited[child] == 1 && child != parent)
                return true;
            // If child is not visited then call DFS for child
            else if(visited[child] == 0) {
                if(DFS(adjList, visited, child, source) == true) {
                    return true;
                }   
            }
        }
    return false;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    int n = B.size();
    // preparing the adjacency list
    // As nodes are numbered from 1 to A
    vector <vector <int>> adjList(A+1);
    for (int i=0; i < n; i++) {
        adjList[B[i][0]].push_back(B[i][1]);
        adjList[B[i][1]].push_back(B[i][0]);
    }
    vector <bool> visited(A+1, 0);
    bool isCyclic = false;
    for (int i=1; i<A+1; i++) {
        if(visited[i] == 0) {
          isCyclic = DFS(adjList, visited, i, -1);
          if(isCyclic == true) {
              return 1;
          }
        }
    }
    return 0;
}
