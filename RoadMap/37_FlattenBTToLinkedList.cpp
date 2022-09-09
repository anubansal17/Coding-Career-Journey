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
// ----Better approach - can be used for preorder, postorder and inorder
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        flatten(root->left);
        flatten(root->right);
        if(root->left) {
            TreeNode* cur = root->left;
            while(cur->right) {
                cur = cur->right;
            } 
            cur->right = root->right;
            root->right = root->left; 
            root->left = NULL;
        } 
    }
};

////////////////--------------------------------------
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* node = root;
        while(node != NULL){
         // check if left subtree is not null
            if(node->left) {
                TreeNode* rightmost = node->left;
                // finding the rightmost element of left subtree
                while(rightmost->right) {
                 rightmost = rightmost->right;
                }
                rightmost->right = node->right;
                node->right = node->left;
                node->left = NULL;
            }
            node = node->right;
        }
    }
};
