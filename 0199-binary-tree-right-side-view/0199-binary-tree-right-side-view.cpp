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
    void solve(vector<int> &nums,int level, TreeNode* root){
        if(!root){
            return;
        }
        if(level==nums.size()){
            nums.push_back(root->val);
        }
        solve(nums,level+1, root->right);
        solve(nums,level+1, root->left);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        solve(ans,0,root);
        return ans;
    }
};