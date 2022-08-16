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
    void makeParent(unordered_map<TreeNode*,TreeNode*> &mp, TreeNode* root){
        queue<TreeNode*> pq;
        pq.push(root);
        while(pq.size()>0){
            TreeNode* temp = pq.front();
            pq.pop();
            if(temp->left){
                mp[temp->left] = temp;
                pq.push(temp->left);
            }
            if(temp->right){
                mp[temp->right] = temp;
                pq.push(temp->right);
            }
        }
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        makeParent(mp,root);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> pq;
        pq.push(target);
        visited[target] = true;
        int level = 0;
        while(pq.size()>0){
            int levelsize=pq.size();
            
            if(level++ == k){
                break;
            }
            for(int i=0;i<levelsize;i++){
                TreeNode* temp = pq.front();
                pq.pop();
                if(temp->left && visited[temp->left]!=true){
                    pq.push(temp->left);
                    visited[temp->left]=true;
                }
                if(temp->right && visited[temp->right]!=true){
                    pq.push(temp->right);
                    visited[temp->right]=true;
                }
                if(mp[temp] && !visited[mp[temp]]){
                    pq.push(mp[temp]);
                    visited[mp[temp]] = true;
                }
            }
        }
        
        
        vector<int> ans;
        while(pq.size()>0){
            TreeNode* temp = pq.front();
            pq.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};