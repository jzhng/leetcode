// 237. Delete Node in a Linked List
// https://leetcode.com/problems/delete-node-in-a-linked-list/description/

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} node
 * @return {void} Do not return anything, modify node in-place instead.
 */
var deleteNode = function(node) {
  if (!node) {
    return null;
  }

  if (!node.next) {
    node = null;
  }

  let delNode = node.next;
  node.val = delNode.val;
  node.next = delNode.next;    
};
