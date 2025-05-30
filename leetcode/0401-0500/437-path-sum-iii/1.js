// 437. Path Sum III
// https://leetcode.com/problems/path-sum-iii/description/

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
 * @return {number}
 */
var pathSum = function(root, sum) {
  if (!root) return 0;

  let res = findPath(root, sum);
  res += pathSum(root.left, sum);
  res += pathSum(root.right, sum);

  return res;
};

function findPath(node, num) {
  if (!node) return 0;

  let res = 0;
  if (node.val === num) {
    res += 1;
  }

  res += findPath(node.left, num - node.val);
  res += findPath(node.right, num - node.val);
  return res;
}
