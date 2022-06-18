/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
  const temp = [];
  let i = 0;
  let j = 0;
  while (i < m || j < n) {
    if (i < m  && j < n) {
      if (nums1[i] > nums2[j]) {
        temp.push(nums2[j++]);
      } else {
        temp.push(nums1[i++]);
      }
    }
    if (i === m) {
      while (j < n) temp.push(nums2[j++]);
    }
    if (j === n) {
      while (i < m) temp.push(nums1[i++]);
    }
  }

  for (let k = 0; k < temp.length; k++) {
    nums1[k] = temp[k];
  }
};

let nums1 = [1, 2, 3, 0, 0, 0],
  m = 3,
  nums2 = [2, 5, 6],
  n = 3;

// let nums1 = [0],
//   m = 0,
//   nums2 = [1],
//   n = 1;
merge(nums1, m, nums2, n);
console.info(nums1);
