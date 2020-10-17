bool isValid(int i, int j, int m, int n) {
    if(i < 0 || i >= m || j < 0 || j >= n) {
        return false;
    }
    return true;
}
void BFS(int m, int n, vector<vector<int>>&visited, vector<vector<char>> adjMatrix, int i, int j) {
    queue <pair<int, int>> que;
    que.push({i,j});
    visited[i][j] = 1;
    pair<int, int> current;
    while(!que.empty()) {
        // We can have adjacent nodes in 4 directions
        current = que.front();
        int curX = current.first;
        int curY = current.second;
        que.pop();
        // check for left element - if it is valid and its value is 1 or 0
        if(isValid(curX-1, curY, m, n) && adjMatrix[curX-1][curY] == '1' && visited[curX-1][curY] == 0) {
            que.push({curX-1, curY});
            visited[curX-1][curY] = 1;
        }
        if (isValid(curX+1, curY, m, n) && adjMatrix[curX+1][curY] == '1' && visited[curX+1][curY] == 0) {
            que.push({curX+1, curY});
            visited[curX+1][curY] = 1;
        }
        if  (isValid(curX, curY-1, m, n) && adjMatrix[curX][curY-1] == '1' && visited[curX][curY-1] == 0) {
            que.push({curX, curY-1});
            visited[curX][curY-1] = 1;
        }
        if (isValid(curX, curY+1, m, n) && adjMatrix[curX][curY+1] == '1' && visited[curX][curY+1] == 0) {
            que.push({curX, curY + 1});
            visited[curX][curY+1] = 1;
        }
    }
}
class Solution {
public:
    // We need to find connected components in grid
    int numIslands(vector<vector<char>>& grid) {
      int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        // Here, adjacency matrix is given
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if((visited[i][j] == 0) && grid[i][j] == '1') {
                    BFS(m, n, visited, grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
