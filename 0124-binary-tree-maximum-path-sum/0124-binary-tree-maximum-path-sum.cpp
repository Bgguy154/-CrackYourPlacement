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
//     int PathSum(TreeNode* root,int &sum){
//         if(!root)return 0;
//         if(!root->left && !root->right) return root->val;
//         int left=PathSum(root->left,sum);
//         int right=PathSum(root->right,sum);
        
//         if(root->right&&root->left){
//             sum=max(sum,root->val+left+right);
//         return root->val+max(left,right);}
        
//         if(!root->right){
//             return root->val+left;
//         }
//         if(!root->left){return root->val +right;}
//     }
    // int maxPathSum(TreeNode* root) {
    //     int sum=INT_MIN;
    //     int val=PathSum(root,sum);
    //     if(root->left && root->right) return sum;
    //     return max(sum,val);
        
        int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    maxPathSumDownFrom(root, ans);
    return ans;
  }

 private:
  // Returns the maximum path sum starting from the current root, where
  // root->val is always included.
  int maxPathSumDownFrom(TreeNode* root, int& ans) {
    if (root == nullptr)
      return 0;

    const int l = max(0, maxPathSumDownFrom(root->left, ans));
    const int r = max(0, maxPathSumDownFrom(root->right, ans));
    ans = max(ans, root->val + l + r);
    return root->val + max(l, r);
    }
    
};