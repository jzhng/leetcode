// 129. Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumNumbers = function(root) {
  let sum = 0;

  const nums = dfs(root);
  for (let num of nums) {
    sum += parseInt(num.join(''));
  }

  return sum;
};

function dfs(node) {
  let nums = [];
  if (!node) return nums;

  if (!node.left && !node.right) {
    nums.push([node.val]);
  }

  for (let path of dfs(node.left)) {
    path.unshift(node.val);
    nums.push(path);
  }
  for (let path of dfs(node.right)) {
    path.unshift(node.val);
    nums.push(path);
  }
  return nums;
}

const {createBinaryTree, TreeNode} = require('../util');
let t1 = createBinaryTree([1, 2, null, null, 3]);
console.info(sumNumbers(t1));
