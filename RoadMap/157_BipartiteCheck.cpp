bool BFS(vector <vector<int>> adjList, vector <bool> &visited, int source, vector <int> &color) {
    queue <int> que;
    que.push(source);
    visited[source] = 1;
    color[source] = 0;
    while(!que.empty()) {
        int current = que.front();
        que.pop();
        for (int i=0; i<adjList[current].size(); i++) {
            int child = adjList[current][i];
            if(visited[child] == 0) {
                visited[child] = 1;
                color[child] = 1- color[current];
                que.push(child);
            }
            // At any point if child is already visited and it has the same color as current, graph is not bipartite
            else if(color[child] == color[current]) {
                return false;
            }
        }
    }
    return true;
}
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // graph can be called as biprtite only if it can be divided into two sets
        // red color - 0
        // blue color - 1
        // Given graph is an adjacency list
        int n = graph.size();
        vector <int> color(n, -1);
        vector <bool> visited(n, 0);
        bool ans = true;
        for (int i=0; i<n; i++) {
            if(visited[i] == 0) {
                if(BFS(graph, visited, i, color) == false) {
                    return false;
                }
            }
        }
        return ans;
    }
};
