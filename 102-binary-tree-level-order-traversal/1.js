// 102. Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
var levelOrder = function(root) {
  const res = [], q = [];
  if (!root) return res;

  q.push({node: root, level: 0});

  while (q.length !== 0) {
    let p = q.shift();
    let node = p.node, level = p.level;
    
    if (level === res.length) {
      res.push([]);
    }
    res[level].push(node.val);
    
    if (node.left) {
      q.push({node: node.left, level: level + 1});
    }
    if (node.right) {
      q.push({node: node.right, level: level + 1});
    }
  }

  return res;
};

const {createBinaryTree, TreeNode} = require('../util');
let tree = createBinaryTree([1, 1, null, 2, null, null, 3]);
console.info(levelOrder(tree));
