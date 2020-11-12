
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
// Time Complexity: O(V+E)
// S.C - O(V)
Node* copyNode(Node* node, unordered_map <Node*, Node*> &mp) {
    // creating a copy if it doesn't exist already
    if(mp.find(node) == mp.end()) {
        mp[node] = new Node(node->val);
        // calling copyNode for its neighbors
        for (Node* neig : node->neighbors) {
            mp[node]->neighbors.push_back(copyNode(neig, mp));
        }
    } 
    return mp[node];
}
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) {
            return node;
        }
        unordered_map <Node*, Node*> mp;
        return copyNode(node, mp);
    }
};
