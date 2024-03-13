/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* path(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root || root==p || root==q){
            return root;
        }
        TreeNode* left = path(root->left,p,q);
        TreeNode* right = path(root->right,p,q);
        
        if(!left and !right){
            return NULL;
        }
        if(!left){
            return right;
        }
        if(!right){
            return left;
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return root;
        }
        return path(root,p,q);
    }
};