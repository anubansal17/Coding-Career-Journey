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
/*
Approach 1: Recursive Solution, T.C - O(n), Auxiliary Space : If we don’t consider size of stack for function calls then O(1) otherwise O(n)
- Traverse the left subtree
- Print the root
- Traverse the right subtree
Approach 2: Iterative solution, T.C - O(n)
- Using stack, we can print the inorder traversal of a binary tree
- Initialise current as root of the tree
- while cur != NULL
- 1. insert cur into stack and cur = cur->next
- 1. keep inserting left of root into stack and do cur = cur->next
- If cur = =NULL and stack is non empty
- pop from stack and print this element and push this popped element->right into stack and again move to step 1
- If cur == null and stack is empty then return
*/
// Approach 1 Implementation
void inOrder(TreeNode* root, vector <int> &traversal) {
    if(root == NULL) {
        return;
    }
    // Traversing the left subtree
    inOrder(root->left, traversal);
    
    // Inserting the root into array
    traversal.push_back(root->val);
    
    // traversing the right subtree
    inOrder(root->right, traversal);
}
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> traversal;
        inOrder(root, traversal);
        return traversal;
    }
    
    
// Approach 2 Implementation
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> traversal;
        stack <TreeNode*> treeStack;
        TreeNode* curr = root;
        // If cur != null or stack is non empty
        while(curr != NULL or treeStack.empty() == false) {
            // Reach till the bottom most left of tree
            while(curr != NULL) {
                treeStack.push(curr);
                curr = curr->left;
            }
            // If curr == null and stack is non empty
            if(curr == NULL and !treeStack.empty()) {
                TreeNode* stackTop = treeStack.top();
                // Pop element from stack
                treeStack.pop();
                // Push this into answer vector
                traversal.push_back(stackTop->val);
                // Make current as right of this popped element
                curr = stackTop->right;
            }
        }
        return traversal;
    }
};
