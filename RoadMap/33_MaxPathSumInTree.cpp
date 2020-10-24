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
int maxSum(TreeNode* root, int &maxm) {
    if(root == NULL) {
        return 0;
    }
    int left = maxSum(root->left, maxm);
    int right = maxSum(root->right, maxm);
    // To consider the negative values
    // To pass it to recursive call
    int temp = max(max(left, right)+root->val, root->val);
    int ans = max(temp, left+right+root->val);
    maxm = max(ans, maxm);
    return temp;
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxm = INT_MIN;
        maxSum(root, maxm);
        return maxm;
    }
};
