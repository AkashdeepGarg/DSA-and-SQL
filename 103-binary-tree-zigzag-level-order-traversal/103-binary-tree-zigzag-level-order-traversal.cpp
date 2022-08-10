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
        
        queue<TreeNode*> pq;
        if(!root){
            return ans;
        }
        pq.push(root);
        bool flag = true;
        while(pq.size()!=0){
            int levelsize = pq.size();
            vector<int> res;
            for(int i=0;i<levelsize;i++){
                TreeNode* temp = pq.front();
                pq.pop();
                
                res.push_back(temp->val);
                if(temp->left){
                    pq.push(temp->left);
                }
                if(temp->right){
                    pq.push(temp->right);
                }
            }
            if(flag){
                ans.push_back(res);
            }
            else{
                reverse(res.begin(),res.end());
                ans.push_back(res);
            }
            
            flag = !(flag);
        }
        
        return ans;
    }
};