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
    void correct(TreeNode* root,int first,int last){
        if(!root){
            return;
        }
        if(root->val==first){
            root->val=last;
        }
        else if(root->val==last){
            root->val=first;
        }
        correct(root->left,first,last);
        correct(root->right,first,last);
    }
    void inorder(TreeNode* root,vector<int> &nums){
        if(!root){
            return;
        }
        if(root->left){
            inorder(root->left,nums);
        }
        nums.push_back(root->val);
        if(root->right){
            inorder(root->right,nums);
        }
    }
    void recoverTree(TreeNode* root) {
        if(!root){
            return;
        }
        int first,last;
        int flag = 0;
        vector<int> nums;
        inorder(root,nums);
        vector<int> copy = nums;
        sort(copy.begin(),copy.end());
        for(int i=0;i<nums.size();i++){
            if(copy[i]!=nums[i]){
                if(flag==0){
                    first = copy[i];
                    flag=1;
                }
                last = copy[i];
            }
        }
        correct(root,first,last);
        return;
    }
};