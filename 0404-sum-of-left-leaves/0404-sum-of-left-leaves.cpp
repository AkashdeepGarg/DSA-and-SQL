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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        if(!root){
            return ans;
        }
        queue <pair<TreeNode*,char>> q;
        q.push({root,'r'});
        while(q.size()>0){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front().first;
                char c = q.front().second;
                q.pop();
                if(!temp->left and !temp->right and c=='l'){
                    ans+=temp->val;
                }
                if(temp->left){
                    q.push({temp->left,'l'});
                }
                if(temp->right){
                    q.push({temp->right,'r'});
                }    
            }
        }
        return ans;
    }
};