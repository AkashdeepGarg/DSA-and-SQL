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
    // First Solution - 
//     void solve(TreeNode* root, vector<int> &ans){
//         if(root->left){
//             solve(root->left,ans);
//         }
//         ans.push_back(root->val);
//         if(root->right){
//             solve(root->right,ans);
//         }
//     }
    
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         if(!root){
//             return ans;
//         }
//         solve(root,ans);
//         return ans;
//     }
    
    // SECOND solution
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        TreeNode* temp = root;
        stack<TreeNode*> s;
        while(true){
            if(temp){
                s.push(temp);
                temp = temp->left;
            }
            else{
                if(s.empty()){
                    return ans;
                }
                temp = s.top();
                ans.push_back(temp->val);
                s.pop();
                temp = temp->right;
            }
        }
        return ans;
    }
};