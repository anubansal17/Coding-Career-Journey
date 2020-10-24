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
bool isIdentical(TreeNode* root1, TreeNode* root2) {
    if(root1 == NULL and root2 == NULL) {
        return 1;
    }
    if(root1 && root2) {
        return (root1->val == root2->val) && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
    }
    return false;
}
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isIdentical(p, q);
    }
};
