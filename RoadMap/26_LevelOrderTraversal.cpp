class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue <TreeNode*> que;
        vector <vector<int>> traversal;
        // Base case
        if(root == NULL) {
            return traversal;
        }
        que.push(root);
        // Keep exploring children of nodes present in queue
        while(!que.empty()) {
            vector <int> level;
            int size = que.size();
            for (int i=0; i< size; i++) {
                 TreeNode* front = que.front();
                level.push_back(front->val);
                que.pop();
                if(front->left != NULL) {
                    que.push(front->left);
                }
                if(front->right) {
                    que.push(front->right);
                }   
            }
            traversal.push_back(level);
        }
        return traversal;
    }
};
