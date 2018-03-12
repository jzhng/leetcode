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

var sumNumbers = function(root) {
  return sum(root, 0);
};

function sum(node, s) {
  if (!node) return 0;

  const num = s * 10 + node.val;
  if (!node.left && !node.right) {
    return num;
  }
  return sum(node.left, num) + sum(node.right, num);
}

const {createBinaryTree, TreeNode} = require('../util');
let t1 = createBinaryTree([1, 2, null, null, 3]);
console.info(sumNumbers(t1));
