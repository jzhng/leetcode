// 230. Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(root, k) {
  let node = root, count = 0;

  const stack = [];
  while (node || stack.length) {
    while (node) {
      stack.push(node);
      node = node.left;
    }
    node = stack.pop();

    if (++count === k) return node.val;
    node = node.right;
  }

  throw(new Error('no solution'));
};

const {createBinaryTree, arrayBinaryTree, TreeNode} = require('../util');
let tree = createBinaryTree([ 0, -3, 9, -10, null, 5 ]);
console.info(kthSmallest(tree, 5));
