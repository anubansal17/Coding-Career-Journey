// Problem: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/

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
    bool isCousins(TreeNode* root, int x, int y) {
        //We are performing level order traversal here
        //We will check if both the nodes at the same level and have different roots then we will               //return true
        TreeNode* par1 = NULL;
        TreeNode* par2 = NULL;
       //Queue to keep track of all the discovered nodes
        queue <pair<TreeNode*, TreeNode*>> que;
        TreeNode* dummy = NULL;
        //pushing NULL as parent of root to make a pair of child and root
        que.push(make_pair(root, dummy));
        //To keep track of front element in the queue
        pair <TreeNode*, TreeNode*> firstEle;
        while(!que.empty()){
            //At an istant the queue will contain all the elements at a certain level
            par1 = NULL;
            par2 = NULL;
            int levelSize = que.size();
            
            while(levelSize != 0){ 
              firstEle = que.front();
                que.pop();
              if(firstEle.first->val == x || firstEle.first->val == y){
                    if(par1 == NULL)
                      par1 = firstEle.second;
                    else{
                       par2 = firstEle.second;
                    }
                     
                  }
                if(firstEle.first->left){
                    que.push(make_pair(firstEle.first->left, firstEle.first));
                }
                if(firstEle.first->right){
                    que.push(make_pair(firstEle.first->right, firstEle.first));
                }
                
                levelSize --;
                //If par1 and par2 are found at same level then no need to proceed further at this                     //level
                if(par1 && par2){
                    break;
                }
                
            }
            if(par1 && par2){
                    return par1 != par2;
                }
                //if both x and y are found at different levels, then one of parents will be equal to                   //NULL
                if((par1 && !par2) || (!par1 && par2)){
                    return false;
                }
        }
        return false;
    }
};
