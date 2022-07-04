// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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
  const res = [];

  function postorder(node) {
    if (node) {
      postorder(node.left);
      postorder(node.right);
      res.push(node.val);
    }
  }
  postorder(root);
  return res;
};

const {createBinaryTree, TreeNode} = require('../util');
let tree = createBinaryTree([1, null, 2, 3]);
console.info(postorderTraversal(tree));

