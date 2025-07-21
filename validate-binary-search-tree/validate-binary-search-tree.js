/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isValidBST = function(root) {
    function isV(node, minNode, maxNode) {
        if (node === null) return true;

        if (minNode !== null && node.val <= minNode.val) return false;
        if (maxNode !== null && node.val >= maxNode.val) return false;

        return isV(node.left, minNode, node) && isV(node.right, node, maxNode);
    }

    return isV(root, null, null);
};
