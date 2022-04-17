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

vector<int>v;
void inorder(TreeNode* root){
    if(root==NULL)return ;
    inorder(root->left);
    v.push_back(root->val);
    inorder(root->right);
}

TreeNode* increasingBST(TreeNode* root) {
     inorder(root);
    TreeNode *head = new TreeNode();
    TreeNode *it=head;
    for(auto x:v){
        it=it->right=new TreeNode(x);
    }
    return head->right;
}
};