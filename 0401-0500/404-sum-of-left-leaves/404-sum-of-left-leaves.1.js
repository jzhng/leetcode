// 404. Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves/description/

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumOfLeftLeaves = function(root) {
  if (!root) return 0;
  return sum(root.left, root) + sum(root.right, root);
};

function sum(node, parent) {
  if (!node) return 0;
  if (!node.left && !node.right && !parent.right) return node.val;

  return sum(node.left, node) + sum (node.right, node);
}
