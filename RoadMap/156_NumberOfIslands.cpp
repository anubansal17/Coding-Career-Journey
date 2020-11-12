bool isValid(int i, int j, int n, int m) {
    if(i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    return true;
}
void BFS(vector<vector<char>> adjMat, vector<vector<bool>> &visited, int i, int j, int n , int m) {
    queue <pair<int, int>> que;
    que.push({i, j});
    visited[i][j] = 1;
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    while(!que.empty()) {
        int curX = que.front().first;
        int curY = que.front().second;
        que.pop();
    // exploring its children
    for (int k=0; k<4; k++) {
        if(isValid(curX+x[k], curY+y[k], n, m) && adjMat[curX+x[k]][curY+y[k]] == '1' && visited[curX+x[k]][curY+y[k]] == 0) {
            que.push({curX+x[k], curY+y[k]});
            visited[curX+x[k]][curY+y[k]] = 1;
            }
        }   
    }
}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        // Adj matrix is given
        vector <vector <bool>> visited(n, vector<bool>(m, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if(visited[i][j] == 0 && grid[i][j] == '1')
                {
                    BFS(grid, visited, i, j, n, m);
                    count++;
                }
            }
        }
            return count;
    }
};
