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
var inorderTraversal = function(root) {
  const res = [], stack = [];

  if (!root) return res;

  stack.push(new Command('g', root));
  while (stack.length !== 0) {
    let cmd = stack.pop();
    if (cmd.s === 'p') {
      res.push(cmd.node.val);
    } else {
      let node = cmd.node;
      if (node.right) {
        stack.push(new Command('g', node.right));
      }
      stack.push(new Command('p', node));
      if (node.left) {
        stack.push(new Command('g', node.left));
      }
    }
  }
  return res;
};

function Command(s, node) {
  this.s = s;
  this.node = node;
}

const {createBinaryTree, TreeNode} = require('../util');
let tree = createBinaryTree([1, null, 2, 3]);
console.info(inorderTraversal(tree));

