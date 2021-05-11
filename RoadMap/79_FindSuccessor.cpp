/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findSuccessor(TreeNode* root, TreeNode* &succ, TreeNode* p) {
        if(root == NULL)
            return;
        if(root->val == p->val)
            findSuccessor(root->right, succ, p);
        if(root->val > p->val) {
            succ = root;
            findSuccessor(root->left, succ, p);
        } else{
            findSuccessor(root->right, succ, p);
        }
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
      TreeNode* succ = NULL;
        findSuccessor(root, succ, p);
        return succ;
    }
};
