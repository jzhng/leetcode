// 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/description/

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
  if (!root) return true;

  if (Math.abs(depth(root.left) - depth(root.right)) > 1) {
    return false;
  }

  return isBalanced(root.left) && isBalanced(root.right);
};

function depth(node) {
  if (!node) return 0;
  return Math.max(depth(node.left), depth(node.right)) + 1;
}

const {createBinaryTree, TreeNode} = require('../util');
let t1 = createBinaryTree([3, 9, null, null, 20, 15, null, null, 7]);
let t2 = createBinaryTree([1, 2, 3, 4, null, null, 4, null, null, 3, null, null, 2]);
console.info(isBalanced(t1));
console.info(isBalanced(t2));
