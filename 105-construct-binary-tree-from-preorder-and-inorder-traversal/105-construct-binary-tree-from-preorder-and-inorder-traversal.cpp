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
    int pre = 0;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int s,int e){
        if(s>e){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[pre++]);
        int in;
        for(int i=0;i<inorder.size();i++){
            if(root->val==inorder[i]){
                in = i;
                break;
            }
        }
        
        root->left = solve(preorder,inorder,s,in-1);
        root->right = solve(preorder,inorder,in+1,e);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size()-1;
        return solve(preorder,inorder,0,n);
    }
};