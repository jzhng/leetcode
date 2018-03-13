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
  if (!root) return null;

  const queue = [ root ], nodes = [];
  while (queue.length) {
    let node = queue.shift();
    nodes.push(node);
    if (node === p || node === q) {
      break;
    }
    
    if (node.left) queue.push(node.left);
    if (node.right) queue.push(node.right);
  }

  while (nodes.length) {
    let node = nodes.pop();
    if (ancestor(node, p) && ancestor(node, q)) {
      return node;
    }
  }

  return null;
};

function ancestor(p, q) {
  if (!p || (!p.left && !p.right)) {
    return false;
  }
  if (p === q || p.left === q || p.right === q) {
    return true;
  }

  return ancestor(p.left, q) || ancestor(p.right, q);
}

const {createBinaryTree, arrayBinaryTree, TreeNode} = require('../util');
let t1 = createBinaryTree([1,2]);
let t2 = createBinaryTree([3,5,1,6,2,0,8,null,null,7,4]);

console.info(lowestCommonAncestor(t1, t1, t1.right));
console.info(lowestCommonAncestor(t2, t2.left, t2.left.right.right));
