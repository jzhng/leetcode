// 189. Rotate Array
// https://leetcode.com/problems/rotate-array/description/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
  const n = nums.length;
  
  k = k % n;
  
  reverse(nums, 0, n-k-1);
  reverse(nums, n-k, n-1);
  reverse(nums, 0, n-1);
};

function reverse(nums, l, r) {
  while (l < r) {
      swap(nums, l++, r--);
  }
}

function swap(nums, i, j) {
  let tmp = nums[i];
  nums[i] = nums[j];
  nums[j] = tmp;
}

const arr = [1, 2, 3, 4, 5, 6, 7];
rotate(arr, 3);
console.info(arr);
