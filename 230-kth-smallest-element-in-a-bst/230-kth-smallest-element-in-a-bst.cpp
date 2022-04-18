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
    void inorder(TreeNode *root,vector<int> &v){
    if(root!=NULL){
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inorder(root,v);
        int n=v.size();
        priority_queue<int> maxheap;
        for(int i=0;i<k;i++)
            maxheap.push(v[i]);
        for(int i=k;i<n;i++){
            maxheap.push(v[i]);
            if(maxheap.size()>k)
                maxheap.pop();
        }
        return maxheap.top();
    }
};