// 257. Binary Tree Paths
// https://leetcode.com/problems/binary-tree-paths/description/

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {string[]}
 */
var binaryTreePaths = function(root) {
  const res = [];

  if (!root) return res;
  if (!root.left && !root.right) {
    res.push(`${root.val}`);
    return res;
  }

  for (let s of binaryTreePaths(root.left)) {
    res.push(`${root.val}->${s}`);
  }

  for (let s of binaryTreePaths(root.right)) {
    res.push(`${root.val}->${s}`);
  }
  return res;
};

const {createBinaryTree, TreeNode} = require('../util');
let tree = createBinaryTree([1, 2, null, 5, null, null, 3]);
console.info(binaryTreePaths(tree));
