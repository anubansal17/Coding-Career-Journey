/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// As given p and q will always exist in the tree, so we need not validate that
TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) {
        return root;
    }
    if(root == p || root == q) {
        return root;
    }
    TreeNode* left = LCA(root->left, p, q);
    TreeNode* right = LCA(root->right, p, q);
    if(left && right) {
        return root;
    }
    return left ? left : right;
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = LCA(root, p, q);
        return ancestor;
    }
};
