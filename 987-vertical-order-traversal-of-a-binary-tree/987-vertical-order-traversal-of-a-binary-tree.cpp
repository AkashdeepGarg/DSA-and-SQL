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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<pair<TreeNode* ,pair<int,int>>> pq;
        map<int,map<int,multiset<int>>> S;
        pq.push({root,{0,0}});
        
        while(pq.size()!=0){
            int levelsize = pq.size();
            for(int i=0;i<levelsize;i++){
                auto t = pq.front();
                pq.pop();
                TreeNode* temp = t.first;
                int ver = t.second.first;
                int level = t.second.second;
                S[ver][level].insert(temp->val);
                if(temp->left){
                    pq.push({temp->left,{ver-1,level+1}});
                }
                if(temp->right){
                    pq.push({temp->right,{ver+1,level+1}});
                }
            }
        }
        
        for(auto p : S){
            vector<int> s;
            for(auto a : p.second){
                s.insert(s.end(),a.second.begin(),a.second.end());
            }
            ans.push_back(s);
        }
        
        return ans;
    }
};