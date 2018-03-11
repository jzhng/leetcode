// 107. Binary Tree Level Order Traversal II
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrderBottom = function(root) {
  const res = [], queue = [];
  if (!root) return res;

  queue.push(root);
  let qLen = queue.length;
  while (qLen !== 0) {
    res.unshift([]);
    for (let i = 0; i < qLen; i++) {
      let node = queue.shift();
      res[0].push(node.val);
      if (node.left) queue.push(node.left);
      if (node.right) queue.push(node.right);
    }
    qLen = queue.length;
  }
  
  return res;
};

const {createBinaryTree, TreeNode} = require('../util');
let tree = createBinaryTree([3, 9, null, null, 20, 15, null, null, 7]);
console.info(levelOrderBottom(tree));
