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
    int mii = INT_MAX;
    int prev = INT_MAX;
    
    void inordeerT(TreeNode* root){
        if(root==NULL) return;
        inordeerT(root->left);
        if(prev!=INT_MAX){
            mii=min(mii,root->val-prev);
        }
        prev=root->val;
        inordeerT(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        // TreeNode* x=root->left;
        // while(!x->left){
        //     root=root->left;
        //     x=x->left;
        // }
        // return (root->val)-(x->val);
        
        inordeerT(root);
        return mii;
    }
};
