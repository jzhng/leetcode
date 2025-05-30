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
  if (!root) return 0;

  let l = root, r = root, height = 0;
  while (r) {
    l = l.left;
    r = r.right;
    height++;
  }

  if (!l) {
    return (1 << height) - 1;
  } else {
    return 1 + countNodes(root.left) + countNodes(root.right);
  }   
};
