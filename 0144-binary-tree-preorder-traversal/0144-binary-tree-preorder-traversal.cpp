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
    void solve(TreeNode* root, vector<int>& temp){
        if(!root){
            return;
        }
        temp.push_back(root->val);
        solve(root->left, temp);
        solve(root->right, temp);
    }
    
   
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        solve(root, result);
        
        return result;
    }
};