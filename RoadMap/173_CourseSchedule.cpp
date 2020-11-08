class Solution {
    /*
    Approach: Directed Graph can be used to solve this problem
    - In this we will check if in any point, back edge exists then we are sure that there would be a cycle in the graph and the ans should be false
    - Back edge is defined as any edge which exists between visited node and other visited node
    - DFS approach would be used to solve the problem as we will first going to check for one vertex and completely exploring one of its branch
    - We are going to use adjacency list for solving this problem
    */ 
    bool dfs(vector <vector <int> >& adj, vector <int>& visited, int v) {
        // If the node has already been visited and we have reached again at this node
        if(visited[v] == 1)
            return false;
        // As we are visiting the node for the first time
        visited[v] = 1;
        // Doing the same for neighbourhood nodes
        for (int ad : adj[v])
            if(!dfs(adj, visited, ad)) return false;
        // After we have completely explored the node, we will assign it value 2
        visited[v] = 2;
        return true;
    }
public:
    bool canFinish(int nums, vector<vector<int>>& prerequisites) {
        vector <vector <int> > adj(nums);
        // Adding values to adjacency list
        for (auto pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }
        // Keeping track of visiting status of the node
        // Status - 0:unvisited, 1:visited, 2:explored
        vector <int> visited(nums, 0);
        for (int i=0; i<nums; ++i)
            if(visited[i] == 0 and !dfs(adj, visited, i)) return false;
        return true;
    }
};
