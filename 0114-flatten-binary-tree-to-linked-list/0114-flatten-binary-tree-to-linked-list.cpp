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
  void flatten(TreeNode* root) {
    if (root == nullptr)
      return;

    while (root) {
      if (root->left) {
        // Find the rightmost root.
        TreeNode* rightmost = root->left;
        while (rightmost->right)
          rightmost = rightmost->right;
        // Rewire the connections.
        rightmost->right = root->right;
        root->right = root->left;
        root->left = nullptr;
      }
      // Move on to the right side of the tree.
      root = root->right;
    }
  }
};