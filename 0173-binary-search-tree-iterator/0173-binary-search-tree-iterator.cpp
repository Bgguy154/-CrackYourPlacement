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
class BSTIterator {
     private:
  int i = 0;
  vector<int> vals;

  void inorder(TreeNode* root) {
    if (root == nullptr)
      return;
    inorder(root->left);
    vals.push_back(root->val);
    inorder(root->right);
  }
public:
    BSTIterator(TreeNode* root) {
          inorder(root);
    }
    
    bool hasNext() {
        return i<vals.size();
    }
    int next(){
        return vals[i++];
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */