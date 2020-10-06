/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // Approach 2: Using stack and queue
 // Approach 1: Using deque
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector <vector <int>> traversal;
    // Base case
    if(A == NULL) {
        return traversal;
    }
    deque <TreeNode*> deq;
    deq.push_front(A);
    bool reverse = false;
    while(!deq.empty()) {
        if(reverse == false) {
            int size = deq.size();
            vector <int> level;
            for (int i=0; i<size; i++) {
                TreeNode* first = deq.back();
                level.push_back(first->val);
                deq.pop_back();
                // Traversing the left child first
                if(first->left) {
                    deq.push_front(first->left);
                }
                if(first->right) {
                    deq.push_front(first->right);
                }
            }
            traversal.push_back(level);
        } else {
            int size = deq.size();
            vector <int> level;
            for (int i=0; i<size; i++) {
                TreeNode* first = deq.front();
                level.push_back(first->val);
                deq.pop_front();
                // Traversing the left child first
                if(first->right) {
                    deq.push_back(first->right);
                }
                if(first->left) {
                    deq.push_back(first->left);
                }
            }
            traversal.push_back(level);
        }
        reverse = !reverse;
    }
            return traversal;
}
