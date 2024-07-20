class Solution {
public:
  bool isSymmetric(TreeNode* root) {
    if (!root) { // Handle the case where the root is null
      return true; // Two empty trees are considered symmetric
    }
    return isSymmetricHelper(root->left, root->right);
  }

private:
  bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
    if (!left && !right) { // Both nodes are null, so they're symmetric
      return true;
    }
    if (!left || !right || left->val != right->val) { // One node is null or values differ
      return false;
    }
    // Recursive calls for symmetric checking
    return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
  }
};
