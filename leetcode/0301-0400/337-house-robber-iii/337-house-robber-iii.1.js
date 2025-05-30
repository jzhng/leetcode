// 337. House Robber III
// https://leetcode.com/problems/house-robber-iii/description/

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
var rob = function(root) {
  if (!root) return 0;

  let val = 0;
  if (root.left) {
    val += rob(root.left.left) + rob(root.left.right);
  }

  if (root.right) {
    val += rob(root.right.left) + rob(root.right.right);
  }

  return Math.max(val + root.val, rob(root.left) + rob(root.right));
};

const { createBinaryTree, TreeNode } = require('../util.js');

const t1 = createBinaryTree([3, 2, 3, null, 3, null, 1]);
console.info(rob(t1));
