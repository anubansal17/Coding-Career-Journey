//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3335/
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
    //Inorder traversal of a BST gives us the elements in sorted order
    vector <int> ans;
    void inOrder(TreeNode* node){
        if(node == NULL){
            return;
        }
        inOrder(node->left);
        ans.push_back(node->val);
        inOrder(node->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root);
       return ans[k-1];
    }
};
