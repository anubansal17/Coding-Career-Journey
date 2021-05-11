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
    TreeNode* constructTree(vector<int> &preorder, int &preIndex, int minm, int maxm, int size) {
        if(preIndex == size)
            return NULL;
        int val = preorder[preIndex];
        if(minm > val || maxm < val)
            return NULL;
        preIndex++;
        TreeNode* root = new TreeNode(val);
        root->left = constructTree(preorder, preIndex, minm, val, size);
        root->right = constructTree(preorder, preIndex, val, maxm, size);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preIndex = 0;
        int n = preorder.size();
        return constructTree(preorder, preIndex, INT_MIN, INT_MAX, n);
    }
};
