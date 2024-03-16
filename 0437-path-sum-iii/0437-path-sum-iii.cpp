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
    long long ans=0;
    
    int solve(TreeNode* root, long long targetSum){
        if(!root){
        return 0;
        }
        if(targetSum - (root->val)==0){
            ans++;
        }
        return solve(root->right,targetSum-root->val) + solve(root->left,targetSum-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        int temp =  pathSum(root->right,targetSum) + pathSum(root->left,targetSum) + solve(root,targetSum);
        return ans;
    }
};