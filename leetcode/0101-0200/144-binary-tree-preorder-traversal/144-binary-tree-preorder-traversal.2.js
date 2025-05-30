/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var preorderTraversal = function(root) {
  const res = [], stack = [];

  let node = root;
  while (node) {
    node.right && (stack.push(node.right));
    node.left && (stack.push(node.left));
    res.push(node.val);
    node = stack.pop();
  }

  return res;
};

const {createBinaryTree, TreeNode} = require('../util');
let tree = createBinaryTree([1, null, 2, 3]);
console.info(preorderTraversal(tree));
