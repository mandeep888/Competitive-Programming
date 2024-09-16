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
    // we will follow the pair approach where we will make a pair of bool and int such that bool will specify if tree is balanced and int will specify height of the node.
    pair<bool,int> isBalancedFast(TreeNode* root){
        //base case if root is null or we are or on leaf node
        if( root == NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        //Now call the function for left and right subtree
        pair<bool,int> left = isBalancedFast(root->left);
        pair<bool,int> right = isBalancedFast(root->right);
        
        //store the values of balnced tree
        bool leftAns = left.first;
        bool rightAns = right.first;
        bool diff = abs(left.second - right.second) <= 1;
        
        //store the answer and update the height
        pair<bool,int> ans;
        ans.second = max(left.second,right.second)+1;
        if(leftAns && rightAns && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return isBalancedFast(root).first;
    }
};