// 108. Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function(nums) {
  return toBST(nums, 0, nums.length - 1);
};

function toBST(nums, l, r) {
  if (l > r) {
    return null;
  }

  const mid = Math.ceil((l+r)/2);
  const node = new TreeNode(nums[mid]);
  node.left = toBST(nums, l, mid - 1);
  node.right = toBST(nums, mid+1, r);

  return node;
}

const {createBinaryTree, arrayBinaryTree, TreeNode} = require('../util');
let tree = sortedArrayToBST([-10, -3, 0, 5, 9]);
console.info(arrayBinaryTree(tree));
