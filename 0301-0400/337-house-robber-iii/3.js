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
  function doRob(node) {
    if (!node) return [0, 0];

    let left = doRob(node.left);
    let right = doRob(node.right);

    return [
      Math.max(left[0], left[1]) + Math.max(right[0], right[1]),
      node.val + left[0] + right[0]
    ];
  }

  const res = doRob(root);
  return Math.max(res[0], res[1]);
};

const { createBinaryTree, TreeNode } = require('../util.js');

const t1 = createBinaryTree([3, 2, 3, null, 3, null, 1]);
console.info(rob(t1));
