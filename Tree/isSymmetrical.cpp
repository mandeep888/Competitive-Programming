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
     bool isMirror(TreeNode* left, TreeNode* right) {
        // If both nodes are null, they are symmetric
        if (!left && !right) return true;
        // If only one is null, they are not symmetric
        if (!left || !right) return false;
        // The values must be equal and their subtrees must be mirrors of each other
        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
    
    // Main function to check if the tree is symmetric
    bool isSymmetric(TreeNode* root) {
        // An empty tree is symmetric
        if (!root) return true;
        // Check if left and right subtrees are mirrors
        return isMirror(root->left, root->right);
    }
};