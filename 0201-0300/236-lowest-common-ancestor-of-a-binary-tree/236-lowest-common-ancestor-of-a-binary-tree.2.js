/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
  if (!root || root === p || root === q) {
    return root;
  }

  let left = lowestCommonAncestor(root.left, p, q);
  let right = lowestCommonAncestor(root.right, p, q);

  return left && right ? root : (left || right);
};

const {createBinaryTree, arrayBinaryTree, TreeNode} = require('../util');
let t1 = createBinaryTree([1,2]);
let t2 = createBinaryTree([3,5,1,6,2,0,8,null,null,7,4]);

console.info(lowestCommonAncestor(t1, t1, t1.right));
console.info(lowestCommonAncestor(t2, t2.left, t2.left.right.right));
