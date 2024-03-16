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
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1 + max(solve(root->left),solve(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        int lh = solve(root->left);
        int rh = solve(root->right);
        return (isBalanced(root->left) and isBalanced(root->right)) and (abs(lh-rh) <= 1);
    }
};