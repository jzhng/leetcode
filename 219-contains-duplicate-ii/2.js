/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
  const set = new Set();
  for (let i = 0; i < nums.length; i++) {
    let num = nums[i];
    if (set.has(num)) {
      return true;
    } else {
      set.add(num);
    }

    if (set.size === k + 1) {
      set.delete(nums[i - k]);
    }
  }
  return false;
};

const nums1 = [ 2, 3, 4, 5, 4, 2], k1 = 1;
const nums2 = [ -1, -1], k2 = 1;
console.info(containsNearbyDuplicate(nums1, k1));
console.info(containsNearbyDuplicate(nums2, k2));
