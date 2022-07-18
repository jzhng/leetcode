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

  if (root) {
    searchBT(root, '', res);
  }
  return res;
};

function searchBT(node, path, res) {
  if (!node.left && !node.right) {
    res.push(path + node.val);
  }

  if (node.left) searchBT(node.left, `${path}${node.val}->`, res);
  if (node.right) searchBT(node.right, `${path}${node.val}->`, res);
}

const {createBinaryTree, TreeNode} = require('../util');
let tree = createBinaryTree([1, 2, null, 5, null, null, 3]);
console.info(binaryTreePaths(tree));
