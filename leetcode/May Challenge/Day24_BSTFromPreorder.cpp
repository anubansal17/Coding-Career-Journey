//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3339/
//M1 - O(N^2)
class Solution {
    TreeNode *makeBST(TreeNode* &root, int ele) {
        if(!root) {
            root = new TreeNode(ele);
            return root;
        }
        if(root->val > ele){
            makeBST(root->left, ele);
        }else{
           makeBST(root->right, ele);
        }
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       
        TreeNode* root = NULL;
        int n = preorder.size();
        for (int i=0; i<n; i++) {
            makeBST(root, preorder[i]);
        }
        return root;
    }   
};
//M2
// Approach - We will keep track of range of the elements that can occur at the left and right side
// O(n)
class Solution {
    int makeBST(vector <int> &preorder, int n, int pos, TreeNode* cur, int left, int right){
       if(pos == n || preorder[pos] < left || preorder[pos] > right) {
           return pos;
       } 
        if(preorder[pos] < cur->val) {
            cur->left = new TreeNode(preorder[pos]);
            pos ++;
            pos = makeBST(preorder, n, pos, cur->left, left, cur->val-1);
        } if(pos == n || preorder[pos] < left || preorder[pos] > right) {
           return pos;
       }
            cur->right = new TreeNode(preorder[pos]);
            pos ++;
            pos = makeBST(preorder, n, pos, cur->right, cur->val+1, right);
            
        return pos;
        
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);
        if(n == 1){
            return root; 
        }
        makeBST(preorder, n, 1, root, INT_MIN, INT_MAX);
        return root;
    }
};
