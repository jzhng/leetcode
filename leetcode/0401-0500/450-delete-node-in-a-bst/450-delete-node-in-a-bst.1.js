// 450. Delete Node in a BST
// https://leetcode.com/problems/delete-node-in-a-bst/description/

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} key
 * @return {TreeNode}
 */
var deleteNode = function(root, key) {
  let curr = root, pre = null;
  while (curr && curr.val !== key) {
    pre = curr;
    if (curr.val < key) {
      curr = curr.right;
    } else {
      curr = curr.left;
    }
  }

  if (!curr) return root;
  let p = curr.left, q = curr.right;
  if (p) {
    if (p.right) {
      let q = p.right;
      while (q.right) {
        p = q;
        q = q.right;
      }
      curr.val = q.val;
      p.right = q.left;
    } else {
      curr.val = p.val;
      curr.left = p.left;
    }
  } else if (q) {  // no left child, have right child
    curr.val = q.val;
    curr.left = q.left;
    curr.right = q.right;
  } else {  // no children, set pre.
    if (!pre) {
      return null;
    } else {
      if (pre.left === curr) {
        pre.left = null;
      } else {
        pre.right = null;
      }
    }
  }

  return root;
};

const {createBinaryTree, arrayBinaryTree, TreeNode} = require('../util');
let t1 = createBinaryTree([5, 3, 6, 2, 4, null, 7]);
let t2 = createBinaryTree([3, 1, null, 2, 4]);
let t3 = createBinaryTree([1, null, 2]);
let t4 = createBinaryTree([1,0,15,null,null,4,35,3,8,25,49,2,null,5,12,22,27,47,null,null,null,null,7,11,13,19,24,26,31,40,48,6,null,9,null,null,14,17,21,23,null,null,null,30,33,39,42,null,null,null,null,null,10,null,null,16,18,20,null,null,null,28,null,32,34,36,null,41,44,null,null,null,null,null,null,null,null,null,29,null,null,null,null,null,37,null,null,43,46,null,null,null,38,null,null,45]);


console.info(arrayBinaryTree(deleteNode(t1, 3)));
console.info(arrayBinaryTree(deleteNode(t2, 3)));
console.info(arrayBinaryTree(deleteNode(t3, 2)));
// console.info(arrayBinaryTree(deleteNode(t4, 22)));
