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
    vector<int>p;
    void i(TreeNode* root){
        if(!root) return;
        i(root->left);
        p.push_back(root->val);
        i(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
      i(root);
        return p;
    }
};