/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //We will store the parents of all nodes in a map
        vector<int> ans;
        if(!root){
            return ans;
        }
        map<TreeNode*, TreeNode*> parent;
        parent[root] = NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left){
                    parent[temp->left] = temp;
                    q.push(temp->left);
                }
                if(temp->right){
                    parent[temp->right] = temp;
                    q.push(temp->right);
                }
            }
        }
        
        map<TreeNode*,int> vis;
        q.push(target);
        vis[target]=1;
        while(q.size()>0){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(k==0){
                    ans.push_back(temp->val);
                }
                else{
                    if(temp->left and vis[temp->left]==0){
                        q.push(temp->left);
                        vis[temp->left]=1;
                        
                    }
                    if(temp->right and vis[temp->right]==0){
                        q.push(temp->right);
                        vis[temp->right]=1;
                    }
                    if(parent[temp] and vis[parent[temp]]==0){
                        q.push(parent[temp]);
                        vis[parent[temp]]=1;
                    }
                }
                
            }
            k--;
        }
        return ans;
    }
};