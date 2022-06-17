// 112. Path Sum
// https://leetcode.com/problems/path-sum/description/

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {boolean}
 */
var hasPathSum = function(root, sum) {
  if (!root) return false;

  if (!root.left && !root.right) {
    return root.val === sum;
  }
  
  return (hasPathSum(root.left, sum - root.val) 
      || hasPathSum(root.right, sum - root.val));
};

const {createBinaryTree, TreeNode} = require('../util');
let t1 = createBinaryTree([1, null, 2, 3]);
console.info(hasPathSum(t1, 6));
