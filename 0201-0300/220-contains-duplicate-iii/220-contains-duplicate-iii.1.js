// 220. Contains Duplicate III
// https://leetcode.com/problems/contains-duplicate-iii/description/

/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} t
 * @return {boolean}
 */
var containsNearbyAlmostDuplicate = function(nums, k, t) {
  const set = new Set();
  for (let i = 0; i < nums.length; i++) {
    let n = nums[i];
    for (let m of set.values()) {
      if (Math.abs(n - m) <= t) {
        return true;
      }
    }
    set.add(n);

    if (set.size === k + 1) {
      set.delete(nums[i - k]);
    }
  }
  return false;
};

const nums = [ 2, 4, 6, 4, 2], k = 1, t = 2;
console.info(containsNearbyAlmostDuplicate(nums, k, t));
