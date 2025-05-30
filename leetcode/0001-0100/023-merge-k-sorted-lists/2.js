// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/description/

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
  const queue = new MinHeap(lists.length);
  const dummyHead = new ListNode(0);
  
  let tail = dummyHead;
  for (let node of lists) {
    if (node) queue.insert(node);
  }

  while (!queue.isEmpty()) {
    tail.next = queue.extractMin();
    tail = tail.next;
    if (tail.next) {
      queue.insert(tail.next);
    }
  }

  return dummyHead.next;
};

function _swap(arr, i, j) {
  let _t = arr[i];
  arr[i] = arr[j];
  arr[j] = _t;
}

class MinHeap {
  constructor(n) {
    this.capacity = n;
    this.count = 0;
    this.data = new Array(n + 1);
  }

  _shiftUp(k) {
    const { data } = this;
    while (k > 1) {
      let p = Math.floor(k / 2);
      if (data[p].val <= data[k].val) {
        break;
      }
      _swap(data, p, k);
      k = p;
    }
  }

  _shiftDown(k) {
    const { count, data } = this;
    while (k * 2 <= count) {
      let j = k * 2;
      if (j + 1 <= count && data[j + 1].val < data[j].val) {
        j += 1;
      }
      if (data[k].val <= data[j].val) {
        break;
      }
      _swap(data, k, j);
      k = j;
    }
  }

  size() {
    return this.count;
  }

  isEmpty() {
    return this.count === 0;
  }

  insert(item) {
    this.data[++this.count] = item;
    this._shiftUp(this.count);
  }

  extractMin() {
    let ret = this.data[1];
    _swap(this.data, 1, this.count--);
    this._shiftDown(1);
    return ret;
  }
}

const {createLinkedList, printLinkedList, ListNode} = require('../util');
let l1 = createLinkedList([1, 2, 3, 4, 5, 6, 7, 8]);
let l2 = createLinkedList([3, 5, 6, 9]);
let l3 = createLinkedList([2, 4, 8, 10, 11, 12, 19]);
let l4 = createLinkedList([0, 1, 2, 3, 4, 5, 6, 7]);
const lists = [l1, l2, l3, l4];
printLinkedList(l1);
printLinkedList(l2);
printLinkedList(l3);
printLinkedList(l4);
printLinkedList(mergeKLists(lists));
