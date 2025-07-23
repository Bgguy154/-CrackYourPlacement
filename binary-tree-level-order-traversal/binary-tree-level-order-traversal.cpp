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
    void d(TreeNode* node,int level,vector<vector<int>> &s){
        if(!node)return;
        if(s.size()==level)s.push_back({});
        
        s[level].push_back(node->val);
        
        d(node->left, level + 1, s);
        d(node->right, level + 1, s);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>s;
       d(root,0,s);
        return s;
    }
};