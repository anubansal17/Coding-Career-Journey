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
    void inorder(TreeNode* root, vector<int> &traversal) {
        if(root == NULL)
            return;
        inorder(root->left, traversal);
        traversal.push_back(root->val);
        inorder(root->right, traversal);
    }
    bool findTarget(TreeNode* root, int k) {
        vector <int> traversal;
        inorder(root, traversal);
        int start = 0;
        int end = traversal.size() - 1;
        while(start < end){
            if(traversal[start]+traversal[end] == k)
                return 1;
            else if(traversal[start]+traversal[end] > k)
                end--;
            else
                start++;
        }
        return 0;
    }
};
