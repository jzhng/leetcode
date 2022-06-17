// 219. Contains Duplicate II
// https://leetcode.com/problems/contains-duplicate-ii/description/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
  const n = nums.length, set = new Set();
  let i = 0;
  while (i < n) {
    if (i > k) {
      set.delete(nums[i - k - 1]);
    }
    let num = nums[i++];
    if (set.has(num)) {
      return true;
    } else {
      set.add(num);
    }
  }
  return false;
};

const nums1 = [ 2, 3, 4, 5, 4, 2], k1 = 2;
const nums2 = [ -1, -1], k2 = 1;
console.info(containsNearbyDuplicate(nums1, k1));
console.info(containsNearbyDuplicate(nums2, k2));
