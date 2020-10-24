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
int height(TreeNode* root, bool &isBalanced) {
    if(root == NULL) {
        return 0;
    }
    int left = height(root->left, isBalanced);
    int right = height(root->right, isBalanced);
    if(abs(right - left) > 1){
        isBalanced = false;
    }
    return 1 + max(left, right);
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        height(root, isBalanced);
        return isBalanced;
    }
};
