/**
* Problem Statement: Clone an undirected graph.
* Each node in the graph contains a label and a list of its neighbors.
**/


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
map < UndirectedGraphNode*, UndirectedGraphNode*> gp{}; //(k, v) -> copy of node k is new node v

UndirectedGraphNode* copyNode(UndirectedGraphNode *node){
    if(gp.find(node) == gp.end()){
        //copy has not created already
        gp[node] = new UndirectedGraphNode(node -> label);
        // As in constructor, we can see we need to pass label
        for(auto &nds: node->neighbors){
            gp[node]->neighbors.push_back(copyNode(nds));
        }
    }
    return gp[node];
}

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    gp.clear();
    
    if(node == NULL){
        return NULL;
    }

    return copyNode(node);
}
