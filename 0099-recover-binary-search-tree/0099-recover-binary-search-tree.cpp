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
// public:
    // void correct(TreeNode* root,int first,int last){
    //     if(!root){
    //         return;
    //     }
    //     if(root->val==first){
    //         root->val=last;
    //     }
    //     else if(root->val==last){
    //         root->val=first;
    //     }
    //     correct(root->left,first,last);
    //     correct(root->right,first,last);
    // }
    // void inorder(TreeNode* root,vector<int> &nums){
    //     if(!root){
    //         return;
    //     }
    //     if(root->left){
    //         inorder(root->left,nums);
    //     }
    //     nums.push_back(root->val);
    //     if(root->right){
    //         inorder(root->right,nums);
    //     }
    // }
    // void recoverTree(TreeNode* root) {
    //     if(!root){
    //         return;
    //     }
    //     int first,last;
    //     int flag = 0;
    //     vector<int> nums;
    //     inorder(root,nums);
    //     vector<int> copy = nums;
    //     sort(copy.begin(),copy.end());
    //     for(int i=0;i<nums.size();i++){
    //         if(copy[i]!=nums[i]){
    //             if(flag==0){
    //                 first = copy[i];
    //                 flag=1;
    //             }
    //             last = copy[i];
    //         }
    //     }
    //     correct(root,first,last);
    //     return;
    // }
    
private: 
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last; 
    void inorder(TreeNode* root) {
        if(root == NULL) return; 
        
        inorder(root->left);
        
        if (root->val < prev->val)
        {
           
            // If this is first violation, mark these two nodes as
            // 'first' and 'middle'
            if ( first == NULL )
            {
                first = prev;
                middle = root;
            }
 
            // If this is second violation, mark this node as last
            else
                last = root;
        }
 
        // Mark this node as previous
        prev = root;
        inorder(root->right); 
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL; 
        prev = new TreeNode(INT_MIN); 
        inorder(root);
        if(first && last) swap(first->val, last->val); 
        else if(first && middle) swap(first->val, middle->val); 
    }
};