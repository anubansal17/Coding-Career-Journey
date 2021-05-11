/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
/*// Approach:
Push all the left nodes to the stack starting from the root in the constructor. This will push the nodes in descending order.
In the hasNext() return true if the stack has elements and false if its empty
In the next(), pop the node from the stack, push to the stack the right subtree of this node and return its value.
*/
stack<TreeNode*> treeStack;
void pushLeft(TreeNode* node){
        if (node != NULL){
            treeStack.push(node);
            pushLeft(node->left);
        }
}
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        int minm;
        TreeNode* stackTop = treeStack.top();
        treeStack.pop();
        pushLeft(stackTop->right);
        return stackTop->val;
    }
    
    bool hasNext() {
    if(!treeStack.empty()) {
        return true;
    } else {
        return false;
    }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
