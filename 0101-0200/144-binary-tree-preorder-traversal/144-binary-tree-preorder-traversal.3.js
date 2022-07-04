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

  let p = root;
  while (p || stack.length !== 0) {
    if (p) {
      stack.push(p);
      res.push(p.val);
      p = p.left;
    } else {
      let node = stack.pop();
      p = node.right;
    }
  }

  return res;
};

const {createBinaryTree, TreeNode} = require('../util');
let tree = createBinaryTree([1, null, 2, 3]);
console.info(preorderTraversal(tree));
