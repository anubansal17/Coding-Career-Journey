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
bool isMirror(TreeNode* root1, TreeNode* root2) {
    if(root1 == NULL and root2 == NULL) {
        return 1;
    }
    if(root1 && root2 && (root1->val == root2->val))
        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    return 0;
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};
