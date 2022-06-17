// 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/description/

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
var rightSideView = function(root) {
  const res = [], queue = [];
  if (!root) return res;

  queue.push(root);
  let qLen = queue.length;
  while (qLen) {
    for (let i = 0; i < qLen; i++) {
      let node = queue.shift();
      if (node.left) queue.push(node.left);
      if (node.right) queue.push(node.right);

      if (i === qLen - 1) {
        res.push(node.val);
      }
    }
    qLen = queue.length;
  }
  return res;
};

const {createBinaryTree, TreeNode} = require('../util');
let tree = createBinaryTree([1, 2, null, 5, null, null, 3, null, 4]);
console.info(rightSideView(tree));
