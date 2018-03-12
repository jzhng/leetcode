/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isBalanced = function(root) {
  return height(root) !== -1;
};

function height(node) {
  if (!node) return 0;

  const lH = height(node.left);
  if (lH === -1) return -1;
  const rH = height(node.right);
  if (rH === -1) return -1;

  if (Math.abs(lH - rH) > 1) return -1;
  return Math.max(lH, rH) + 1;
}

const {createBinaryTree, TreeNode} = require('../util');
let t1 = createBinaryTree([3, 9, null, null, 20, 15, null, null, 7]);
let t2 = createBinaryTree([1, 2, 3, 4, null, null, 4, null, null, 3, null, null, 2]);
console.info(isBalanced(t1));
console.info(isBalanced(t2));
