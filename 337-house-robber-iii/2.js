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
    if (!node) return 0;
    if (map.has(node)) return map.get(node);

    let val = 0;
    if (node.left) {
      val += doRob(node.left.left) + doRob(node.left.right);
    }
    if (node.right) {
      val += doRob(node.right.left) + doRob(node.right.right);
    }

    val = Math.max(val + node.val, doRob(node.left) + doRob(node.right));
    map.set(node, val);
    return val;
  }

  const map = new Map();
  return doRob(root);
};

const { createBinaryTree, TreeNode } = require('../util.js');

const t1 = createBinaryTree([3, 2, 3, null, 3, null, 1]);
console.info(rob(t1));
