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
    bool isSame(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL and root2 == NULL) {
            return true;
        }
        if (root1 == NULL || root2 == NULL) 
            return false; 
        if(root1->val == root2->val)
            return isSame(root1->left, root2->left) and isSame(root1->right, root2->right);
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL and subRoot == NULL)
            return 1;
        if(root == NULL || subRoot == NULL)
            return 0;
        if(root->val == subRoot->val and isSame(root->left, subRoot->left) and isSame(root->right, subRoot->right))
            return true;
            
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
