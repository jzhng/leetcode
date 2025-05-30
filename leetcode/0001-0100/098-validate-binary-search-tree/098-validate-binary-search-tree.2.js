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
var isValidBST = function(root) {
  if (!root) return true;
  
  let stack = [], pre = null, node = root;
  while (node || stack.length) {
    while (node) {
      stack.push(node);
      node = node.left;
    }
    node = stack.pop();

    if (pre && node.val <= pre.val) {
      return false;
    }
    pre = node;
    node = node.right;
  }
  return true;
};

const {createBinaryTree, TreeNode} = require('../util');
let t1 = createBinaryTree([10, 5, null, null, 15, 11, null, null, 20]);
console.info(isValidBST(t1));
