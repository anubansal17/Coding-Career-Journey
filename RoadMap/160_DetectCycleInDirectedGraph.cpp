bool dfs(vector <vector <int> >& adj, vector <int>& visited, int v) {
        // As we are visiting the node for the first time
        visited[v] = 1;
        // Doing the same for neighbourhood nodes
        for (int ad : adj[v]) {
            // If the node has already being visiting  and we have reached again at this node
            if(visited[ad] == 1)
                return true;
            else if(visited[ad] == 2) {
                continue;
            }
            else if(dfs(adj, visited, ad)) return true;
        }
        // After we have completely explored the node, we will assign it value 2
        visited[v] = 2;
        return false;
    }
int Solution::solve(int nums, vector<vector<int> > &prerequisites) {
    vector <vector <int> > adj(nums+1);
        // Adding values to adjacency list
        for (auto pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }
        // Keeping track of visiting status of the node
        // Status - 0:unvisited, 1:visiting, 2:visited
        vector <int> visited(nums+1, 0);
        for (int i=1; i<=nums; ++i)
            if(visited[i] == 0 and dfs(adj, visited, i)) return true;
        return false;
}
