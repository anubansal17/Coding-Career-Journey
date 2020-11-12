int BFS(vector <int> arr, int N) 
{ 
    // The graph has N vertices. Mark all the vertices as  not visited 
    vector <bool> visited(100, 0);
    // Create a queue for BFS 
    queue<int> que; 
    int throws = 0;
    // Mark the node 0 as visited and enqueue it. 
    visited[0] = true; 
    que.push(0);  // Enqueue 0'th vertex 
  // Do a BFS starting from vertex at index 0 
    while (!que.empty()) 
    { 
        int size = que.size();
        for (int i=0; i<size; i++) {
            int current = que.front(); 
            que.pop(); 
            // If front vertex is the destination vertex,  we are done 
            if (current == N-1) {
                return throws;    
            }
            for (int j=current+1; j<=(current+6) && j<N; ++j) 
            { 
                // If this cell is already visited, then ignore 
                if (!visited[j]) { 
                    visited[j] = 1; 
                    int num;
                    if (arr[j] != -1) 
                        num = arr[j]; 
                    else
                        num = j; 
                    que.push(num); 
                } 
            }   
        }
        throws++;
    } 
    return -1; 
} 
int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    // Here, we are starting from index 0
    // Destination would be 99
    vector <int> arr(100, -1);
    for (auto num : A) {
        arr[num[0]-1] = num[1]-1;
    }
    for (auto num : B) {
        arr[num[0]-1] = num[1]-1;
    }
    int ans = BFS(arr , 100);
    return ans;
}
