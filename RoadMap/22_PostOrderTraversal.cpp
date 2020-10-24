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
class Solution {
public:
    // reverse pre order traversal with a bit modification - Root Right Left => Left Right Root
    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> traversal;
        stack <int> reverseTraversal;
        stack <TreeNode*> treeStack;
        TreeNode* cur = root;
        while(cur || !treeStack.empty()) {
            while(cur) {
                reverseTraversal.push(cur->val);
                // Pushing left child into stack
                if(cur->left) {
                    treeStack.push(cur->left);
                }
                cur = cur->right;
            }
            if(!treeStack.empty()) {
            TreeNode* top = treeStack.top();
            treeStack.pop();
            cur = top;
            }
        }
       while(!reverseTraversal.empty()) {
           traversal.push_back(reverseTraversal.top());
           reverseTraversal.pop();
       }
        return traversal;
    }
};
