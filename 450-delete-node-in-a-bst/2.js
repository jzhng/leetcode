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

// got runtime error on leetcode though pass local test,
// no clue yet.
var deleteNode = function(root, key) {
  if (!root) return null;

  if (key < root.val) {
    root.left = deleteNode(root.left, key);
  } else if (key > root.val) {
    root.right = deleteNode(root.right, key);
  } else {
    if (!root.left) {
      return root.rigt;
    } else if (!root.right) {
      return root.left;
    }

    let node = root.right;
    while (node.left) {
      node = node.left;
    }
    root.val = node.val;
    root.right = deleteNode(root.right, node.val);
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
