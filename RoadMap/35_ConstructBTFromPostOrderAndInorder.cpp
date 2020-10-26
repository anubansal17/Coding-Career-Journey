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
 1. Take an element from preorder traversal and increment the preIndex
 2. Check for this element in inorder traversal - Use maps to do it in O(1), otherwise it would take O(n)
 3. Elements at the left side will be in left subtree of the node and elements at the right side will in the right side of the node
 4. Repeat above for all the elements in array of preorder traversal
 */
TreeNode* constructTree(vector<int> &A, vector<int> &B, int &preIndex, int start, int end, unordered_map <int, int> &mp) {
    if(start > end) {
         return NULL;
     }
    // Making new node with data present at preIndex in A and increment the index
     TreeNode* newNode = new TreeNode(A[preIndex--]);
     // If start and end in the vector B are same, this means the node doesn't have any child
     if(start == end) {
         return newNode;
     }
     
     // Searching for the element in inorder traversal to decide the left subtree elements and right subtree elements
     int inIndex = mp[newNode->val];
     // Constructing right subtree
     newNode->right = constructTree(A, B, preIndex, inIndex+1, end, mp); 
    // Constructing left sub tree
     newNode->left = constructTree(A, B, preIndex, start, inIndex-1, mp);
     return newNode;
 }
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int end = postorder.size()-1;
    unordered_map <int, int> mp;
    long long int i = 0;
    if(postorder.size() == 0) {
        return NULL;
    }
    // Store indexes of each element in inorder traversal
    for (auto num : inorder) {
        mp[num] = i++;
    }
    int postIndex = postorder.size()-1;
    TreeNode* root = constructTree(postorder, inorder, postIndex, 0, end, mp);
    return root;   
    }
};
