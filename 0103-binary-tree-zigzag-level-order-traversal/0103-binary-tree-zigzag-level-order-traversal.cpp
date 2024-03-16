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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        int flag=0;
        
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            flag++;
            int n = q.size();
            vector<int> t;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                t.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(flag%2==0){
                reverse(t.begin(),t.end());
            }
            ans.push_back(t);
        }
        return ans;
    }
};