// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/description/

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
  const res = [], set1 = new Set(nums1), set2 = new Set(nums2);
  set2.forEach((v) => { if (set1.has(v)) { res.push(v)}});
  return res;
};

const nums1 = [1, 2, 2, 1], nums2 = [2, 2];
console.info(intersection(nums1, nums2));
