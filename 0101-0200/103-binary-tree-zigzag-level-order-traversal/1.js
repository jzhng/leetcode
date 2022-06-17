// 103. Binary Tree Zigzag Level Order Traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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
var zigzagLevelOrder = function(root) {
  const res = [], queue = [];
  if (!root) return res;

  queue.push(root);
  let qLen = queue.length, level = 0;
  while (qLen !== 0) {
    res.push([]);
    let last = res.length - 1;
    for (let i = 0; i < qLen; i++) {
      let node = queue.shift();
      if (level % 2) {
        res[last].unshift(node.val);
      } else {
        res[last].push(node.val);
      }
      if (node.left) queue.push(node.left);
      if (node.right) queue.push(node.right);
    }
    qLen = queue.length;
    level++;
  }

  return res;
};

const {createBinaryTree, TreeNode} = require('../util');
let tree = createBinaryTree([3, 9, null, null, 20, 15, null, null, 7]);
console.info(zigzagLevelOrder(tree));
