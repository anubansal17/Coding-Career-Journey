// Approach1: Using Level order traversal
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector <int> rightView;
        // Base case
        if(root == NULL) {
            return rightView;
        }
        queue <TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int curSize = que.size();
            for(int i=0; i<curSize; i++) {
                TreeNode* front = que.front();
                que.pop();
                // If its the last element present in this level
                if(i == curSize-1) {
                    rightView.push_back(front->val);
                }
                if(front->left) {
                    que.push(front->left);
                }
                if(front->right) {
                    que.push(front->right);
                }
            }
        }
        return rightView;
    }
};
// Approach2: Using recursion
// We will keep track of max level and cur level of traversal
// Traverse the right subtree first and then the left
// The first time the level increases, it would be incase of right most child
void findRightView(TreeNode* root, vector<int> &rightView, int &maxLevel, int curLevel) {
     if(root == NULL) {
            return ;
    }
    if(maxLevel < curLevel) {
        maxLevel++;
        rightView.push_back(root->val);
    }
    // Traversing the right sub tree first
    findRightView(root->right, rightView, maxLevel, curLevel+1);
    // Traversing the left sub tree
    findRightView(root->left, rightView, maxLevel, curLevel+1);
}
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector <int> rightView;
        int maxLevel = 0;
        findRightView(root, rightView, maxLevel, 1);
        return rightView;
    }
};
