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
    void solve(TreeNode* root, vector<int> &temp){
        if(root->left){
            solve(root->left,temp);
        }
        temp.push_back(root->val);
        if(root->right){
            solve(root->right,temp);
        }
    }
    
    int getMinimumDifference(TreeNode* root) {
        int ans=0;
        if(!root){
            return ans;
        }
        vector<int> temp;
        solve(root,temp);
        if(temp.size()<2){
            return 0;
        }
        ans=temp[1]-temp[0];
        for(int i=1;i<temp.size()-1;i++){
            ans = min(ans,(temp[i+1]-temp[i]));
        }
        return ans;
    }
};