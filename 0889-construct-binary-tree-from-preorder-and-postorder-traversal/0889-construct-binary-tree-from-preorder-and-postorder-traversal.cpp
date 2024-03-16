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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        map<int,int> pre;
        for(int i=0;i<preorder.size();i++){
            pre[preorder[i]] = i;
        }
        map<int,int> post;
        for(int i=0;i<postorder.size();i++){
            post[postorder[i]] = i;
        }
        map<int,int> vis;
        vis[pre[0]]=1;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                int ni = pre[temp->val]+1;
                if(ni < preorder.size() and vis[preorder[ni]]==0){
                    TreeNode* lefti = new TreeNode(preorder[ni]);
                    temp->left = lefti;
                    vis[preorder[ni]]=1;
                    q.push(lefti);
                }
                int pi = post[temp->val] - 1;
                if(pi >= 0 and vis[postorder[pi]]==0){
                    TreeNode* righti = new TreeNode(postorder[pi]);
                    temp->right = righti;
                    vis[postorder[pi]]=1;
                    q.push(righti);
                }
            }
        }
        
        return root;
    }
};