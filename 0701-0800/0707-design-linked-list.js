function Node(val) {
  this.val = val;
  this.next = null;
}
/**
 * Initialize your data structure here.
 */
var MyLinkedList = function() {
  this.head = new Node(0);
};

/**
 * Get the value of the index-th node in the linked list. If the index is invalid, return -1.
 * @param {number} index
 * @return {number}
 */
MyLinkedList.prototype.get = function(index) {
  let i = 0;
  let cur = this.head.next;
  while (cur) {
    if (i++ === index) return cur.val;
    cur = cur.next;
  }

  return -1;
};

/**
 * Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtHead = function(val) {
  const node = new Node(val);
  node.next = this.head.next;
  this.head.next = node;
};

/**
 * Append a node of value val to the last element of the linked list.
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtTail = function(val) {
  let pre = this.head;
  while (pre.next) {
    pre = pre.next;
  }
  pre.next = new Node(val);
};

/**
 * Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
 * @param {number} index
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtIndex = function(index, val) {
  let i = 0;
  let pre = this.head;
  while (pre) {
    if (i++ === index) {
      let node = new Node(val);
      node.next = pre.next;
      pre.next = node;
      break;
    }
    pre = pre.next;
  }
};

/**
 * Delete the index-th node in the linked list, if the index is valid.
 * @param {number} index
 * @return {void}
 */
MyLinkedList.prototype.deleteAtIndex = function(index) {
  let i = 0;
  let pre = this.head;
  while (pre.next) {
    if (i++ === index) {
      pre.next = pre.next.next;
      break;
    }
    pre = pre.next;
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * var obj = new MyLinkedList()
 * var param_1 = obj.get(index)
 * obj.addAtHead(val)
 * obj.addAtTail(val)
 * obj.addAtIndex(index,val)
 * obj.deleteAtIndex(index)
 */


// var obj = new MyLinkedList();
// console.info(obj);
// obj.addAtHead(1);
// console.info(obj);
// obj.addAtTail(3);
// console.info(obj);
// obj.addAtIndex(1, 2);
// console.info(obj);
// console.info(obj.get(1));
// obj.deleteAtIndex(1);
// console.info(obj.get(1));

var obj = new MyLinkedList();
console.info(obj);
obj.addAtTail(1);
console.info(obj);
console.info(obj.get(0));
