// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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
  const arr = [];

  function preorder(node) {
    if (node) {
      arr.push(node.val);
      preorder(node.left);
      preorder(node.right);
    }
  }

  preorder(root);
  return arr;
};

const {createBinaryTree, TreeNode} = require('../util');
let tree = createBinaryTree([1, null, 2, 3]);
console.info(preorderTraversal(tree));
