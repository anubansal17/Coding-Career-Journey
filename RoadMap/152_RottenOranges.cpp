bool isValid(int i, int j, int n, int m) {
    if(i >= n || i < 0 || j < 0 || j >= m) {
        return false;
    }
    return true;
}

// Approach: Multi source BFS
int BFS(vector<vector<int>> &grid, int n, int m, int &freshOranges) {
        queue<pair<int, int>> que;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    que.push({i, j});
                } else if(grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }
    int timeElapsed = 0;
    // upward - x, y+1, d - x, y-1, r - x+1, y, l - x-1, y
    int x[4] = {0, 0, 1, -1};
    int y[4] = {1, -1, 0, 0};
    while(freshOranges != 0 && !que.empty()) {
        int size = que.size();
        // As we can move in 4 directions, we will make an array for that
        timeElapsed ++;
        // For all the sources present in que
        for (int i=0; i<size; i++) {
            pair<int, int> current = que.front();
            que.pop();
            int curX = current.first;
            int curY = current.second;
            for (int j=0; j<4; j++) {
                // pushing adjacents into the que
                if(isValid(curX+x[j], curY+y[j], n, m) && grid[curX+x[j]][curY+y[j]] == 1)                  {
                    que.push({curX+x[j], curY+y[j]});
                    grid[curX+x[j]][curY+y[j]] = 2;
                    freshOranges --;
                }
            }
        }
    }
    return freshOranges == 0 ? timeElapsed : -1;
}
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int freshOranges = 0;
        vector<vector<bool>> visited(n, vector<bool> (m, 0));
        int ans = BFS(grid, n, m,freshOranges);
        return ans;
    }
};
