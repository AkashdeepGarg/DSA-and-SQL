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
    int ans=1;
    void solve(TreeNode* root, int val){
        if(root==NULL){
            return;
        }
        int maxr = val;
        int maxl = val;
        if(root->left != NULL and root->left->val >=val){
            ans++;
            maxl = root->left->val;
        }
        if(root->right != NULL and root->right->val >=val){
            ans++;
            maxr = root->right->val;
        }
        solve(root->left,maxl);
        solve(root->right,maxr);
        
        return;
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        solve(root,root->val);
        return ans;
    }
};