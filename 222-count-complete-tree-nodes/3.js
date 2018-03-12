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

var countNodes = function(root) {
  let count = 0, node = root;
  let h = height(node);
  while (node) {
    if (height(node.right) === h - 1) {
      count += 1 << h - 1;
      node = node.right;
    } else {
      count += 1 << h - 2;
      node = node.left;
    }
    h--;
  }
  return count;
};

function height(node) {
  let height = 0;
  while (node) {
    node = node.left;
    height++;
  }
  return height;
}
