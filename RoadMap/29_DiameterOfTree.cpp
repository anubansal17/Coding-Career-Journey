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
int height(TreeNode* root, int &diameter) {
    if(root == NULL) {
        return 0;
    }
    int left = height(root->left, diameter);
    int right = height(root->right, diameter);
    diameter = max(diameter, left+right+1);
    return 1 + max(left, right);
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
         if(root == NULL) {
            return 0;
         }
        height(root, diameter);
        // As in the que, 1 minus actual diameter is required
        return diameter-1;
    }
};
