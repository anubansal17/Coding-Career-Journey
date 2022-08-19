class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == p)
            return findSmallest(root->right);
        TreeNode* l = NULL;
        if(root->val > p->val) {
            l = inorderSuccessor(root->left, p);
            return l?l:root;
        }
        return root->right?inorderSuccessor(root->right, p):NULL;
    }
    TreeNode* findSmallest(TreeNode* root) {
        if(root== NULL)
            return root;
        if(root->left)
           return findSmallest(root->left);
        return root;
    }
};
