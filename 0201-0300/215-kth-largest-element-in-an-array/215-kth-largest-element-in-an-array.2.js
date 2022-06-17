/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function(nums, k) {
  // use partition mechanism in quick sort
  function _partition(arr, l, r) {
    _swap(arr, l, Math.floor(Math.random() * (r - l + 1)) + l);
    const v = arr[l];
    let j = l;
    for (let i = l + 1; i <= r; i++) {
      if (arr[i] < v) {
        _swap(arr, i, ++j);
      }
    }
    _swap(arr, l, j);
    return j;
  }

  const n = nums.length;
  let l = 0, r = n - 1, p = 0;
  while (l <= r) {
    p = _partition(nums, l, r);
    if (p === n - k) {
      break;
    } else if (p < n - k) {
      l = p + 1;
    } else {
      r = p - 1;
    }
  }

  return nums[p];
};

function _swap(arr, a, b) {
  let _t = arr[a];
  arr[a] = arr[b];
  arr[b] = _t;
}

let nums = [3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6];
console.info(findKthLargest(nums, 2));
