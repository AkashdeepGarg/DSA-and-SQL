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
    vector<string> ans; 

void treePath(TreeNode* root, string s){
    if(!root) return; // Base case
    s += to_string(root->val); // Adding the current node's value to string
	
	// if root has any of the the child present then only add "->" to current string
    if(root->left || root->right){ 
        s += "->";
    }
	
	// if current node has no children then push the current string to ans vector
    if(!root->left && !root->right){
        ans.push_back(s);
        return;
    }
	// recursive call
    treePath(root->left,s);
    treePath(root->right,s);
}

vector<string> binaryTreePaths(TreeNode* root) {
    treePath(root,"");
    return ans;
}
};