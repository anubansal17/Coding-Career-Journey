// Recursive Solution
void preOrder(TreeNode* root, vector <int> &traversal) {
    if(root == NULL) {
        return;
    }
    // Inserting the root into array
    traversal.push_back(root->val);
    
    // Traversing the left subtree
    preOrder(root->left, traversal);
    
    // traversing the right subtree
    preOrder(root->right, traversal);
}
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> traversal;
        preOrder(root, traversal);
        return traversal;
    }
};

// Iterative Solution
// Approach 2: Iterative Approach: Using stack, T.C- O(n), S.C- O(n)
// Start from root node
// Push this to stack
// 1. Pop the top element from stack and print it
// 2. Push the right child of popped element into stack
// 3. push the left child of popped element into stack
// Move back to step 1
/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> traversal;
        stack <TreeNode*> treeStack;
        TreeNode* cur = root;
        treeStack.push(cur);
        // Base case
        if(root == NULL){
            return traversal;
        }
        // While stack is not empty
        while (!treeStack.empty()) {
            TreeNode* stackTop = treeStack.top();
            treeStack.pop();
            traversal.push_back(stackTop->val);
            if(stackTop->right)
                treeStack.push(stackTop->right);
            if(stackTop->left)
                treeStack.push(stackTop->left);
        }
        return traversal;
    }
};
*/
// Approach 3: Optimization for approach 2, T.C- O(n) S.C(O(h))
/*
- While traversing the left subtree, keep printing the left child while exists 
- and simultaneously, push right child of every node in an auxiliary stack
- Once we reach a null node, pop a right child from the auxiliary stack and repeat the process while the auxiliary stack is not-empty.
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    
        vector <int> traversal;
        stack <TreeNode*> treeStack;
        TreeNode* cur = root;
        // While stack is not empty
        while (!treeStack.empty() || cur != NULL) {
            
            // Traversing the left subtree
            while(cur != NULL) {
              traversal.push_back(cur->val);
                if(cur->right) {
                  treeStack.push(cur->right);   
                }
                cur = cur->left;
            }
            // If stack is not empty then pop the element from stack and make it as current
            if(!treeStack.empty()) {
                TreeNode* stackTop = treeStack.top();
                treeStack.pop();
                cur = stackTop;
            }
        }
        return traversal;
    }
};
