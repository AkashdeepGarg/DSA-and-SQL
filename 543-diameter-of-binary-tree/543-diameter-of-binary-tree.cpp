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
    int diameter(TreeNode* root, int& result){
        if(root==NULL)
            return 0;
        int l = diameter(root->left,result);
        int r = diameter(root->right,result);
        
        int temp = 1+ max(l,r);
        int ans = max(temp,(1+r+l));
        result = max(ans,result);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int result=INT_MIN;
        diameter(root,result);
        return result-1;
        
    }
};