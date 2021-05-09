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
    bool isBST(TreeNode* root, long minm, long maxm) {
        if(root == NULL)
            return 1;
        if(minm < root->val && maxm > root->val && isBST(root->left, minm, root->val) && isBST(root->right, root->val, maxm)){
            return true;
        }
        
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root, INT64_MIN, INT64_MAX);
    }
};
