bool isValid(int i, int j, int A, int B) {
    
    if(i<0 || i>=A || j<0 || j>=B) {
        return false;
    }
    return true;
}
int BFS(int A, int B, int i, int j, vector <vector<bool>> &visited, int targetX, int targetY) {
    queue <pair<int, int> > que;
    que.push({i, j});
    visited[i][j] = 1;
    int dist = 0;
    while(!que.empty()) {
        int size = que.size();
        for (int j=0; j<size; j++) {
            pair<int, int> current = que.front();
            que.pop();
            int curX = current.first;
            int curY = current.second;
            if((curX == targetX) && (curY == targetY)) {
                return dist;
            }
            // Exploring all 8 directions from current element
            // As kinight can move in 8 directions
            int x[8]= {-2, -2, -1, -1, 1, 1, 2, 2};
            int y[8]= {-1, 1, -2, 2, -2, 2, -1, 1};
            for (int k=0; k<8; k++) {
                if(isValid(curX+x[k], curY+y[k], A, B) && visited[curX+x[k]][curY+y[k]]==0) {
                    visited[curX+x[k]][curY+y[k]] = 1;
                    que.push({curX+x[k], curY+y[k]});
                    }
                }   
            }
            dist++;
    }
    return -1;
}
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector <vector <bool>> visited(A, vector <bool> (B, 0));
    // If we run bfs on the starting point, the first distance that would be found will be our minimum ditance of dest from source
    int ans;
    ans = BFS(A, B, C-1, D-1, visited, E-1, F-1);
    return ans;
}
