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
