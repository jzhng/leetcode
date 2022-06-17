// 113. Path Sum II
// https://leetcode.com/problems/path-sum-ii/description/

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
 * @return {number[][]}
 */
var pathSum = function(root, sum) {
  const res = [];

  if (!root) return res;
  if (!root.left && !root.right && root.val === sum) {
    res.push([sum]);
  }

  for (let path of pathSum(root.left, sum - root.val)) {
    path.unshift(root.val);
    res.push(path);
  }
  for (let path of pathSum(root.right, sum - root.val)) {
    path.unshift(root.val);
    res.push(path);
  }
  return res;
};

const {createBinaryTree, TreeNode} = require('../util');
let t1 = createBinaryTree([1, null, 2, 3]);
console.info(pathSum(t1, 6));
