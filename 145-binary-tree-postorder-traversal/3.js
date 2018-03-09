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
var postorderTraversal = function(root) {
  const res = [], stack = [];

  let p = root, last = null;
  while (p || stack.length !== 0) {
    if (p) {
      stack.push(p);
      p = p.left;
    } else {
      let top = stack[stack.length - 1];
      if (top.right && last !== top.right) {
        p = top.right;
      } else {
        res.push(top.val);
        last = top;
        stack.pop();
      }
    }
  }
  return res;
};

const {createBinaryTree, TreeNode} = require('../util');
let tree = createBinaryTree([1, null, 2, 3]);
console.info(postorderTraversal(tree));

