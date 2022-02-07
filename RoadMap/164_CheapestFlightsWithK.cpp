//TLE
typedef pair<int, pair<int, int>> ppi;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
       // Making a weighted adjacency list from the given info
        vector <vector< pair<int, int> >> adjList(n);
        for (auto num : flights) {
            adjList[num[0]].push_back({num[1], num[2]});
        }
        // making a min heap with weight as a key and pair of node and k as value
        priority_queue<ppi, vector<ppi>, greater<ppi>> que;
        que.push({0, {src, K}});
        while(!que.empty()) {
            ppi current = que.top();
            que.pop();
            int curWeight = current.first;
            int curVertex = current.second.first;
            int stopsLeft = current.second.second;
            // If current vertex == destination
            if(curVertex == dst){
                return curWeight;
            }
            // If required number of stops for popped node exceeds k, then ignore it
            if(stopsLeft < 0) {
                continue;
            }
             // exploring its adjacents
            for (int i=0; i<adjList[curVertex].size(); i++) {
                int adjNode = adjList[curVertex][i].first;
                int adjWeight = adjList[curVertex][i].second;
                // Weight of source-current edge + weight of current-adjacent edge
                que.push({curWeight + adjWeight, {adjNode, stopsLeft-1}});
            }
        }
        return -1;
    }
};

// More optimised
#define ppi pair<int, pair<int, int>>
class Solution {
public:
    int djikstra(vector<vector<pair<int, int>>> &adjList, int src, int dest, int k) {
        priority_queue<ppi, vector<ppi>, greater<ppi>> nodeDist;
        nodeDist.push({0, {src, -1}});
        int n = adjList.size();
        vector<int> visited(n, 0);
        while(!nodeDist.empty()) {
            ppi cur = nodeDist.top();
            nodeDist.pop();
            int curWt = cur.first;
            int node =  cur.second.first;
            int stopsDone = cur.second.second;
            //cout<<"node"<<node;
            if(visited[node] and visited[node] < stopsDone+1)
                continue;
             if(node == dest and stopsDone <= k)
                return curWt;
            visited[node] = stopsDone+1;
            for(int i=0; i<adjList[node].size(); i++) {
                int child = adjList[node][i].first;
                int childWt = adjList[node][i].second;
                 nodeDist.push({curWt + childWt, {child, stopsDone + 1}});  
            }
        }
        return -1;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int edges = flights.size();
        vector<vector<pair<int, int>>> adjList(n);
        for(int i=0; i<edges; i++) {
            adjList[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
        }
        return djikstra(adjList, src, dst, k);
        
    }
};
