function ListNode(val) {
  this.val = val;
  this.next = null;
}

/*
 * create a linked list from an array, for example:
 * transfer [1, 2, 3, 4] 
 * to        1 -> 2 -> 3 -> 4 -> null
 */
function createLinkedList(arr) {
  const n = arr.length;
  if (n === 0) return null;
  let head = new ListNode(arr[0]);
  let cur = head;
  for (let i = 1; i < n; i++) {
    cur.next = new ListNode(arr[i]);
    cur = cur.next;
  }
  return head;
}

function printLinkedList(head) {
  let cur = head, s = '';
  while (cur) {
    s += `${cur.val} -> `;
    cur = cur.next;
  }
  s += 'null';
  console.info(s);
}

function TreeNode(val) {
  this.val = val;
  this.left = this.right = null;
}

/*
 * create a binary tree  from an array, for example:
 * transfer [1, null, 2, 3] 
 * to         1
 *             \
 *              2
 *             /
 *            3
 */
function createBinaryTree(arr) {
  const n = arr.length, stack = [];
  if (n === 0) return null;

  let root = new TreeNode(arr[0]), i = 1;
  stack.push(root);
  while (i < n) {
    let parent = stack[stack.length - 1];
    let v = arr[i++];
    if (typeof v !== 'undefined') {
      if (v === null) {
        parent.left = null;
        v = arr[i++];
        if (typeof v !== 'undefined') {
          stack.pop();
          if (v === null) {
            parent.right = null;
          } else {
            let child = new TreeNode(v);
            parent.right = child;
            stack.push(child);
          }
        }
      } else {
        let child = new TreeNode(v);
        if (!parent.left) {
          parent.left = child;
        } else {
          parent.right = child;
        }
        stack.push(child);
      }
    }
  }

  return root;
}

module.exports = { createLinkedList, printLinkedList, ListNode, createBinaryTree, TreeNode };
