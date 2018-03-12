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
var sumOfLeftLeaves = function(root) {
  if (!root) return 0;

  let res = 0;
  const { left, right } = root;
  if (left) {
    if (!left.left && !left.right) {
      res += left.val;
    } else {
      res += sumOfLeftLeaves(left);
    }
  }
  res += sumOfLeftLeaves(right);
  
  return res;
};
