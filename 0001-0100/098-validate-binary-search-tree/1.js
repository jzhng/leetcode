// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isValidBST = function(root) {
  if (!root) return true;
  
  let { left, right } = root;
  if (left) {
    while (left.right) {
      left = left.right;
    }
    if (root.val <= left.val) {
      return false;
    }
  }

  if (right) {
    while (right.left) {
      right = right.left;
    }
    if (root.val >= right.val) {
      return false;
    }
  }

  return isValidBST(root.left) && isValidBST(root.right);
};

const {createBinaryTree, TreeNode} = require('../util');
let t1 = createBinaryTree([10, 5, null, null, 15, 11, null, null, 20]);
console.info(isValidBST(t1));
