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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int ans = INT_MIN;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(q.size()>0){
            int n = q.size();
            int mmin = q.front().second;
            int first, last;
            for(int i=0;i<n;i++){
                int curr = q.front().second - mmin;
                TreeNode* temp = q.front().first;
                q.pop();
                if(i==0){
                    first=curr;
                }
                if(i==n-1){
                    last=curr;
                }
                if(temp->left){
                    q.push({temp->left,(long long)2*curr + 1});
                }   
                if(temp->right){
                    q.push({temp->right,(long long)2*curr+2});
                }
            }
            ans = max(ans,last-first+1);
        }
        return ans;
        
    }
};