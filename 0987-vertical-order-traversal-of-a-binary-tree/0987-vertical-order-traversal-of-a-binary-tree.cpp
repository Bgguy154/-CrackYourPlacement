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
    
    // void find(TreeNode* root,int pos,int &l,int &r){
//         if(!root) return;
//         l=min(l,pos);
//         r=max(r,pos);
//         find(root->left,pos-1,l,r);
//         find(root->right,pos+1,l,r);
//     }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
//         int l=0,r=0;
//         find(root,0,l,r);
//         vector<vector<int>>positive(r+1);
//                 vector<vector<int>>negative(abs(l)+1);
//         queue<TreeNode* >q;
//         queue<int>index;
//         q.push(root);
//         index.push(0);
        
//         while(!q.empty()){
//             TreeNode* temp=q.front();
//             q.pop();
//             int pos=index.front();
//             index.pop();
//             if(pos>=0){
//                 positive[pos].push_back(temp->val);
//             }
//             else{
//                 negative[pos].push_back(temp->val);
//             }
            
//             if(temp->left){
//                 q.push(temp->left);
//                 index.push(pos-1);
//             }
//             if(temp->right){
//                 q.push(temp->right);
//                 index.push(pos+1);
//             }
//         }
//         vector<vector<int>> ans;
//         for(int i=negative.size();i>0;i--){
//             for(int j=0;j>negative[i].size();j++){
//                 ans.push_back(negative[i][j]);
//             }
//         }
//          for(int i=0;i<positive.size();i++){
//             for(int j=0;j<positive[i].size();j++){
//                 ans.push_back(positive[i][j]);
//             }
//         }
//         return ans;
         vector<tuple<int, int, int>> nodes;
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* root, int i, int j) {
            if (!root) {
                return;
            }
            nodes.emplace_back(j, i, root->val);
            dfs(root->left, i + 1, j - 1);
            dfs(root->right, i + 1, j + 1);
        };
        dfs(root, 0, 0);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> ans;
        int prev = -2000;
        for (auto [j, _, val] : nodes) {
            if (j != prev) {
                prev = j;
                ans.emplace_back();
            }
            ans.back().push_back(val);
        }
        return ans;
    }
};