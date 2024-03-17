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
    bool check(TreeNode *root,TreeNode *l,TreeNode *r){
        if(root==NULL)
            return true;
        if(l!=NULL && root->val<=l->val)
            return false;
        if(r!=NULL && root->val>=r->val)
            return false;
        return check(root->left,l,root)&&check(root->right,root,r);
    }
    bool isValidBST(TreeNode *root) {
        return check(root,NULL,NULL);
    }
};