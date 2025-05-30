// 88. Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/description/

/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
  let _arr = Array.from(nums1);
  let i, j, k = 0;
  for (i = 0, j = 0; i < m && j < n;) {
    nums1[k++] = (_arr[i] < nums2[j] ? _arr[i++] : nums2[j++]);
  }

  while (i < m) {
    nums1[k++] = _arr[i++];
  }

  while (j < n) {
    nums1[k++] = nums2[j++];
  }
};

let nums1 = [1, 3, 5];
let nums2 = [2, 4, 6];
merge(nums1, 3, nums2, 3);
console.info(nums1);
